Pod::Spec.new do |s|
  s.name         = "MailCore2-CP"

  s.version      = "1.0.0"

  s.summary      = "Mailcore 2 fork by Cirruspath"

  s.description  = "MailCore 2 provide a simple and asynchronous API to work with e-mail protocols IMAP, POP and SMTP."

  s.homepage     = "https://github.com"

  s.license      = "BSD"

  s.authors      = [{ "dkhamsing" => "dkhamsing@cirruspath.com" }, { "jafework" => "jafework@cirruspath.com" }]

  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/cirruspath/mailcore2.git", :tag => s.version.to_s }

  s.requires_arc = false

  s.vendored_frameworks = "MailCore.framework"
end
