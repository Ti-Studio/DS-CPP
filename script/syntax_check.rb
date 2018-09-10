#!/usr/bin/env ruby

require 'yaml'

tests = YAML.load_file (if ARGV.length >= 1 then
                          ARGV[0]
                        else
                          'tests.yml'
                        end)

result = 0
tests['syntax_check'].each do |f|
  system 'g++', '-fsyntax-only', f or result = 1
end

if result != 0
  exit result
end

puts "Syntax check passed!"
