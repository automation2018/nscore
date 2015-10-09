#!/usr/bin/env ruby
#--
# Automates SSH task. 
# Runs command over SSH connection 
#
# Author: Ankur Srivastava
# Last Modified: 
#   1. 9/9/2015 - Initial version
#++

begin 
    require 'net/ssh'
rescue LoadError
    # install the ssh gem if not available
    puts "Required net/ssh gems is not installed"
    puts "Installing now"
    puts "Running command: sudo gem install net-ssh"
    `gem install net-ssh`
end

require 'optparse'

# Command line parsing
opts = OptionParser.new do |opts|
    opts.on("-h", "--hostname HOSTNAME", String, "hostname of the remote server") do |arg|
        @hostname = arg
    end
    opts.on("-u", "--username USERNAME", String, "username") do |arg|
        @username = arg
    end
    opts.on("-p", "--password PASSWORD", String, "password") do |arg|
        @password = arg
    end
    opts.on("-c", "--command COMMAND", String, "command to run") do |arg|
        @command = arg
    end
end
opts.parse!


# Prints help if required arguments are not provided
# in the command line
if @hostname.nil? || @username.nil? || @password.nil? || @command.nil?
    puts opts.help
    exit
end


begin
    # Create a SSH tunnel by calling the start method of SSH class
    # password is to be passed as hash, since other methods
    # are also available to SSH to machine.
    # This ensures, we are using the password mechanism
    tunnel = Net::SSH.start(@hostname, @username, :password=>@password, :timeout=>30)

    # Once the tunnel is created execute the underlying commmand 
    # and print the result to the screen.
    # This is blocking and will wait till the command returns
    # Don't pass any command that will run indefinitely
    #
    # This tunnel can be used to run multiple commands over the
    # same connection. Thus reducing the time and latency in 
    # multiple connects.
    # TODO: Accept commands as array and run each command over 
    # the same tunnel
    console_output = tunnel.exec!(@command)
    puts console_output

rescue StandardError => e
    # This will rescue all standard error
    # such as no route to host etc, name
    # or service not known
    puts e.to_s
rescue Timeout::Error 
    puts " Connection timed out"
rescue Net::SSH::AuthenticationFailed
    puts " Authentication Failed"
end
