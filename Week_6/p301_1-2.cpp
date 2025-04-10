---------------------------
|         MyTime          |
---------------------------
| - hour: int             |
| - minute: int           |
| - second: int           |
| - millisecond: int      |
---------------------------
| + convert(duration: double): void |
| + print(): void                   |
| + add(t: MyTime): MyTime          |
| + reset(): void                   |
| + read(): void                    |
---------------------------
MyTime 클래스는 시간 정보를 저장하고 처리하기 위한 클래스이다.

[멤버 변수]
- hour, minute, second, millisecond의 4가지 정보를 저장하며 모두 private으로 선언하였다.

[멤버 함수]
- convert(double duration): 초 단위의 실수 시간을 시, 분, 초, 밀리초로 변환한다.
- print(): 현재 시간 정보를 형식화하여 출력한다.
- add(MyTime t): 다른 MyTime 객체와의 시간을 더한 MyTime 객체를 반환한다.
- reset(): 모든 시간 정보를 0으로 초기화한다.
- read(): 사용자로부터 시간 정보를 입력받는다.

모든 함수는 public으로 선언되었으며, 클래스 외부에서 사용할 수 있도록 구성하였다.
