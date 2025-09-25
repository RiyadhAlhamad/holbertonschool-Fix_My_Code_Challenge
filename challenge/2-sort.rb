#!/usr/bin/env ruby
# Sort arguments numerically and print one per line

# نأخذ فقط القيم التي هي أعداد صحيحة (بإشارة سالبة أو بدون)
nums = ARGV.select { |arg| arg.match?(/\A-?\d+\z/) }
           .map(&:to_i)
           .sort

nums.each { |n| puts n }
