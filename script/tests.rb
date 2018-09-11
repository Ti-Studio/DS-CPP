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

cmd = ['g++', '-I.'] + cxxflags
tests['test'].each do |f|
  puts "Compiling check #{f}"
  system *cmd, '-o', 'a.out', f or (
    puts "Failed to compile #{f}"
    result += 1
    next
  )
  puts "Running check for #{f}"
  begin
    system './a.out' or (
      puts "Tests in #{f} failed!"
      result += 1
      next
    )
  ensure
    File.delete './a.out'
  end
end

if result != 0
  puts "#{result} error#{'s' if result > 1} found."
  exit result
end

puts "Syntax check passed!"
