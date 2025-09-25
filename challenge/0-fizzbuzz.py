#!/usr/bin/python3
import sys

def fizzbuzz(n: int) -> None:
    if n < 1:
        return
    print(" ".join(
        ("FizzBuzz" if i % 15 == 0 else
         "Fizz" if i % 3 == 0 else
         "Buzz" if i % 5 == 0 else
         str(i))
        for i in range(1, n + 1)
    ))

if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print("Missing number")
        print("Usage: ./0-fizzbuzz.py <number>")
        print("Example: ./0-fizzbuzz.py 89")
        sys.exit(1)
    try:
        number = int(sys.argv[1])
    except ValueError:
        print("Missing number")
        print("Usage: ./0-fizzbuzz.py <number>")
        print("Example: ./0-fizzbuzz.py 89")
        sys.exit(1)
    fizzbuzz(number)
