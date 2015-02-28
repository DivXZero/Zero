
include Zero

class MyTestClass < Test

  def initialize
	self.print('It Lives!!');
  end

end

myVar = MyTestClass.new()

puts myVar.add(13, 27);