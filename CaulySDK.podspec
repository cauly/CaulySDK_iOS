Pod::Spec.new do |s|
    s.name         = "CaulySDK"
    s.version      = "3.1.22"
    s.summary      = "CaulySDK for iOS"
    s.description  = "CaulySDK for iOS"
    s.homepage     = "https://www.cauly.net/index.html#/"
    s.license = { :type => 'MIT', :text => 'LICENSE' }
    s.author             = { "cauly" => "cauly@fsn.co.kr" }
    s.source       = { :git => 'https://github.com/cauly/CaulySDK_iOS.git'}
    s.vendored_frameworks = "CaulySDK.xcframework"
    s.platform = :ios
    s.swift_version = "4.2"
    s.ios.deployment_target  = '12.0'

    s.frameworks = [
        'AVKit',
        'UIKit',
        'Foundation',
        'CoreGraphics',
        'QuartzCore',
        'SystemConfiguration',
        'MediaPlayer',
        'CFNetwork',
        'MessageUI',
        'EventKit',
        'AdSupport'
    ]

    s.pod_target_xcconfig = { 
        'ENABLE_BITCODE' => 'NO', 
        'OTHER_LDFLAGS' => '-ObjC',
        'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
    }
    s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }

end