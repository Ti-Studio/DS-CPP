#!/usr/bin/env ruby

require 'yaml'

tests = YAML.load_file (if ARGV.length >= 1 then
                          ARGV[0]
                        else
                          'tests.yml'
                        end)

result = 0

cxxflags = if tests.include? 'cxxflags'
             tests['cxxflags']
           else
             []
           end

# Syntax check

cmd = ['g++', '-fsyntax-only'] + cxxflags
tests['syntax_check'].each do |f|
  puts "Performing syntax check for #{f}"
  system *cmd, f or result += 1
end

if result != 0
  puts "#{result} error#{result > 1 ? 's' : ''} found."
  exit result
end

puts "Syntax check passed!"
