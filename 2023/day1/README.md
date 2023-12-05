## DAY 1

- [문제](https://adventofcode.com/2023/day/1)
- [문제의 입력](https://adventofcode.com/2023/day/1/input)

### Part 1

문제의 입력이 문자열로 주어진다.  
해당 문자열에서 처음으로 나오는 숫자와, 마지막으로 나오는 숫자를 찾아 2자리 숫자를 만든 뒤, 모든 숫자의 합을 구해야 한다.

예시는 아래와 같다:
```
1abc2 --> 12
pqr3stu8vwx --> 38
a1b2c3d4e5f --> 15
treb7uchet --> 77
```
위와 같은 문자열 입력이 주어진다면, 정답은 142가 된다.

#### 예시 입력
```
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet
```

#### 예시 정답
```
142
```

#### [풀이](part_one.cpp)

그냥 왼쪽에서 한번, 오른쪽에서 한번 숫자를 찾으면 된다.

### Part 2

문제의 입력이 문자열로 주어진다.  
이번에는 영어로 표현한 숫자들도 숫자로 취급한다.
```
two1nine --> 29
eighttwothree --> 83
abcone2threexyz --> 13
xtwone3four --> 24
4nineeightseven2 --> 42
zoneight234 --> 14
7pqrstsixteen --> 76
```

#### 예시 입력
```
two1nine
eightwothree
abcone2threexyz
xtwone3four
4nineeightseven2
zoneight234
7pqrstsixteen
```

#### 예시 정답
```
281
```

#### [풀이](part_two.cpp)

아호-코라식으로 문자열을 스캔해서 풀었다.  
문제의 입력이 크지 않아서 그냥 숫자 영문을 숫자로 모두 바꾼 뒤 풀어도 될 것 같다.