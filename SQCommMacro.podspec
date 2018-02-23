#
# Be sure to run `pod lib lint SQCommMacro.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'SQCommMacro'
  s.version          = '0.1.0'
  s.summary          = '公共的宏定义'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
App统一的公共的宏定义，涉及屏幕宽高信息，系统版本信息，Log信息，颜色，字体...
                       DESC

  s.homepage         = 'https://github.com/SQKB/SQCommMacro'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'SQKB' => 'SQKB' }
  s.source           = { :git => 'https://github.com/SQKB/SQCommMacro.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'SQCommMacro/Classes/**/*'
  
  # s.resource_bundles = {
  #   'SQCommMacro' => ['SQCommMacro/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
