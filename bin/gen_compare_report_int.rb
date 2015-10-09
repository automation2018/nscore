#!/usr/bin/env ruby

require 'optparse'

@parser = OptionParser.new do |opts|
    opts.on('-f', '--file FILE', 'result file') do |arg|
        @file = arg
    end
    opts.on('-o', '--outfile OUTFILE', 'the outfile to write to') do |arg|
        @outfile = arg
    end
    opts.on('-t', '--tolerance TOLERANCE', Float, 'the tolerance pct') do |arg|
        @tolerance = arg
    end
end
@parser.parse!

unless @file && @outfile
    puts @parser.help
    exit
end

is_baseline = false
@testruns = []
@details = []

File.open(@file).each do |line|
    caseid, tr, categoryid, compid, status, desc = line.chomp.split(',')
    @details << "#{caseid}:#{desc}"
    unless is_baseline
        @baseline = tr
        is_baseline = true
        next
    end
    @testruns << tr
end

cmd = "gen_compare_report.rb" \
      " -b #{@baseline}" \
      " -t #{@testruns.join(',')}" \
      " -d \"#{@details.join(',')}\"" 

cmd += " -p #{@tolerance}" if @tolerance

html = `#{cmd}`

File.open(@outfile, 'w').write(html)
