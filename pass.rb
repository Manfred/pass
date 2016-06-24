require 'zlib'

File.open('pass.bin', 'wb') do |bin|
  bin.write("HTTP/1.1 200 OK\r\n")
  bin.write("Content-Type: text/html; charset=utf-8\r\n")
  bin.write("Content-Encoding: gzip\r\n")
  bin.write("\r\n")

  writer = Zlib::GzipWriter.new(bin, Zlib::BEST_COMPRESSION)
  writer.write(File.read('index.html'))
  writer.close
end