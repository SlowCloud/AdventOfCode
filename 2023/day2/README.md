## DAY 2

- [문제](https://adventofcode.com/2023/day/2)
- [문제의 입력](https://adventofcode.com/2023/day/2/input)

### Part 1

게임의 기록이 주어진다.
빨간 상자가 12개, 녹색 상자가 13개, 파란 상자가 14개가 있을 때, 진행 가능한 게임들의 아이디의 합을 구해야 한다.

#### 예시 입력
```
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
```

#### 예시 정답
```
8
```

1번, 2번, 5번 게임만이 진행 가능한 게임이다.

#### [풀이](part_one.cpp)

C++에선 문자열 처리가 꽤 번거롭다. 다행히도, 2개씩 받아서 처리가 가능하도록 문자열이 정리되어 있어서 비교적 간결하게 구현이 가능했다.

우선 한 줄씩 문자열 처리를 가능하게 전처리했다.

이후, 각 줄마다 'Game'과 'id:'를 미리 기록해두고, 숫자와 색깔 문자열 2개를 받아가면서 해당 게임이 가능한 게임인지 검사를 진행했다.

### Part 2

이번에는 각 게임마다 필요한 최소 상자들의 곱의 합을 구하는 문제이다.

#### 예시 입력
```
Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green
Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue
Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red
Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red
Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green
```

#### 예시 정답
```
2286
```

1번 게임에서는 빨간 상자 4개, 녹색 상자 2개, 파란 상자 6개가 있으면 된다. 글므로 1번 게임에서 필요한 상자들의 곱은 48이다. 2~5번 게임들에 대해서도 해당 곱을 구한 뒤, 모두 더한 값이 2286이다.

#### [풀이](part_two.cpp)

문제에서 요구하는 대로 구현하면 된다. 1번 문제 풀이를 조금 바꾸어 사용하면 된다.