#!/usr/bin/env ruby
require "optparse"
require "logger"


@NS_WDIR = ENV["NS_WDIR"]
@logger = Logger.new STDOUT
@logger.level = Logger::ERROR
@REGEX = {
    :request_sent_per_sec => /\d+\|HTTP Requests\(NA\)\|\d+\|\d+\|(?<metric>Requests Sent\/Sec\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :avg_resp_time => /\d+\|HTTP Requests\(NA\)\|\d+\|\d+\|(?<metric>Average Response Time \(Secs\)\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
#    :avg_trans_resp_time => /\d+\|Transactions\(NA\)\|\d+\|\d+\|(?<metric>Average Transaction Response Time \(Secs\)\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/,
    :yg_per_min => /\d+\|JRockit Java GC Stats\(AppTier>fedora-96>cav-stf-atg\)\|\d+\|\d+\|(?<metric>Number of Young GC\/Min\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    #:tenure_per_min => /\d+\|JRockit Java GC Stats\(AppTier>fedora-96>cav-stf-atg\)\|\d+\|\d+\|(?<metric>Number of Tenured GC\/Min\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :time_used_in_gc => /\d+\|JRockit Java GC Stats\(AppTier>fedora-96>cav-stf-atg\)\|\d+\|\d+\|(?<metric>Time used in GC \(Pct\)\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :cpu_time_pct => /\d+\|Process Stats Ex\(AppTier>fedora96>cav-stf-atg\)\|\d+\|\d+\|(?<metric>Cpu Time\(Pct\)\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :wrt => /\d+\|SysStats Linux Extended\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>Processes Waiting For Run Time\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :wfus => /\d+\|SysStats Linux Extended\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>Processes Waiting For UnInterruptible Sleep\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
 #   :block_read => /\d+\|SysStats Linux Extended\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>Disk Blocks Read\/Sec\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
  #  :block_write => /\d+\|SysStats Linux Extended\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>Disk Blocks Written\/Sec\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :interrupts => /\d+\|SysStats Linux Extended\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>Interrupts\/Sec\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :context_switches => /\d+\|SysStats Linux Extended\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>Context Switches\/Sec\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :cpu_util_pct => /\d+\|SysStats Linux Extended\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>CPU Utilization \(Pct\)\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :cpu_queue => /\d+\|SysStats Linux Extended\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>CPU Queue \(%\)\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :load_avg => /\d+\|UpTime\(AppTier>fedora-96\)\|\d+\|\d+\|(?<metric>Load Average Over 1 Minute\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :bt_per_sec => /\d+\|Business Transactions\(AppTier>fedora96>atg>Others\)\|\d+\|\d+\|(?<metric>Requests per sec\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :bt_resp_time => /\d+\|Business Transactions\(AppTier>fedora96>atg>Others\)\|\d+\|\d+\|(?<metric>Average Response Time \(ms\)\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    :fp_per_sec => /\d+\|FlowPath Stats\(AppTier>fedora96>atg\)\|\d+\|\d+\|(?<metric>Flowpaths per sec\(NA\))\|(?<avg>[\d.]+)\|(?<min>[\d.]+)\|(?<max>[\d.]+)/m,
    
}
@parser = OptionParser.new do |opts|
    opts.on("-t", "--testrun TESTRUN", "the testrun number") do |arg|
        @testrun = arg
    end
end
@parser.parse!


def main
   gdf_file = @NS_WDIR + '/logs/TR' + @testrun + "/summary_gdf.data"
   data = read_summary_gdf(gdf_file)

   @logger.info "#{@gdf_file} size: #{data.length}"
   if data.length == 0
       puts "Unable to read summary gdf file"
       exit 1
   end

   match = process(data)
end

def read_summary_gdf(f)
    data = ""
    if File.exist? f
        data = File.read f
    end
    data
end


def process(data)
    @logger.info "REGEX = #{@REGEX[:request_sent_per_sec]}"
    @REGEX.each_key do |k|
        @logger.info "REGEx = #{k}"
        m= @REGEX[k].match(data)
        if m
           puts "#{m[:metric]},#{m[:avg]},#{m[:min]},#{m[:max]}"
        end
    end
end


if __FILE__ == $0
    if @testrun.nil?
        puts @parser.help
        exit 1
    end
    main
end
