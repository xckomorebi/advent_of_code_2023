DAY=2

part%: part%.cpp
	g++ -std=c++17 -o $@ $^

.PHONY: input
input:
	@curl https://adventofcode.com/2023/day/$(DAY)/input -H "Cookie: session=$(AOCSESSION)" > input.txt