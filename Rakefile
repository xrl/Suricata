require 'open-uri'

namespace "build" do
  desc "Build all necessary dependencies"
  task :all => [:environment,:libnet]

  task :environment do
    @root = Dir.pwd
    @build = @root + "/build"
    Dir.mkdir(@build) if Dir[@build].empty?
    Dir.chdir(@build)
  end

  desc ""
  task :libnet do
    tarball = "https://github.com/xrl/libnet/zipball/libnet-1.1.6-rc4"
    `wget #{tarball} -O libnet.tar.gz`
    `unzip libnet.tar.gz`
    Dir.chdir Dir.glob("*xrl-libnet*/libnet").first
    `./autogen.sh && ./configure --prefix=#{@build} && make && make install`
  end
end
