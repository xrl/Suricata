require 'open-uri'
require 'logger'

MANIFEST = {
  :libnet => {
    :url => "https://github.com/xrl/libnet/zipball/libnet-1.1.6-rc4",
    :filename => "libnet.zip"
  },
  :libpcap => {
    :url => "http://www.tcpdump.org/release/libpcap-1.3.0.tar.gz",
    :filename => "libpcap-1.3.0.tar.gz"
  },
  :libmagic => {
    :url => "http://voxel.dl.sourceforge.net/project/libmagic/libmagic/ALPHA/libmagic-alpha.tar.gz",
    :filename => "libmagic-alpha.tar.gz"
  }
}

PACKAGES = %w{ libnet1 libnet1-dev libpcap0.8 libpcap-dev libmagic-dev }

namespace "build" do
  desc "Build all necessary dependencies"
  task :all => [:environment,:packages]

  task :environment do
    @root = Dir.pwd
    @build = @root + "/build"
    Dir.mkdir(@build) if Dir[@build].empty?
    Dir.chdir(@build)
    @logger = Logger.new($stdout)
    @logger.level = Logger::INFO
  end

  task :packages do
    @logger.info "Downloading packages"
    `aptitude download #{PACKAGES.join(' ')}`
    Dir.glob("*.deb").each do |pkg_name|
      @logger.info "Unpacking #{pkg_name}"
      `dpkg-deb -x #{pkg_name} .`
    end
  end

  task :download do
    MANIFEST.each do |name,details|
      @logger.info "Downloading #{name}"
      `wget #{details[:url]} -O #{details[:filename]}`
    end
  end

  desc ""
  task :libnet do
    @logger.info "Building libnet"
    Dir.chdir @build

    `unzip -o #{MANIFEST[:libnet][:filename]}`
    Dir.chdir @build + "/" + Dir.glob("*xrl-libnet*/libnet").first
    `./autogen.sh && ./configure --prefix=#{@build} && make && make install`
  end

  task :libpcap => [:environment,:download] do
    @logger.info "Building libpcap"
    Dir.chdir @build

    `tar xzf #{MANIFEST[:libpcap][:filename]}`
    target = @build + "/" + MANIFEST[:libpcap][:filename].gsub(".tar.gz","")
    Dir.chdir target
    `./configure --prefix=#{@build}`
    `make && make install`
  end

  task :libmagic => [:environment, :download] do

  end
end
