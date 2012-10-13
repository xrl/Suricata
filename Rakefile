require 'open-uri'
require 'logger'

namespace "build" do
  desc "Build all necessary dependencies"
  task :all => [:environment,:libnet]

  task :environment do
    @root = Dir.pwd
    @build = @root + "/build"
    Dir.mkdir(@build) if Dir[@build].empty?
    Dir.chdir(@build)
    @logger = Logger.new($stdout)
    @logger.level = Logger::INFO
  end

  desc ""
  task :libnet do
    @logger.info "Downloading libnet"
    tarball = "https://github.com/xrl/libnet/zipball/libnet-1.1.6-rc4"
    `wget #{tarball} -O libnet.tar.gz`
    @logger.info "Building libnet"
    `unzip -F libnet.tar.gz`
    Dir.chdir Dir.glob("*xrl-libnet*/libnet").first
    `./autogen.sh && ./configure --prefix=#{@build} && make && make install`
  end
end
