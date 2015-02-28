
require_relative 'logger.rb'

testLog = Logger.new()

testLog.print('o_O')

puts $hardware.inspect()

$hardware.each do |name|
	puts name
end