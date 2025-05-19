// MonsterWorld3.java

// 문제: 다양한 몬스터 종류를 클래스로 만들고, 상속을 활용해 공통 동작은 부모 클래스에 정의하고, 개별 동작은 자식 클래스에서 구현한다.

abstract class Monster {
    String name;

    Monster(String name) {
        this.name = name;
    }

    void display() {
        System.out.println(name + "이(가) 등장했습니다!");
    }

    abstract void move(); // 각 몬스터 고유의 이동 방식
}


class Zombie extends Monster {
    Zombie() {
        super("좀비");
    }

    @Override
    void move() {
        System.out.println("정신없이 돌아다닌다.");
        System.out.println("- 현재 위치에서 인접한 방향으로 무작위로 움직인다.");
    }
}


class Vampire extends Monster {
    Vampire() {
        super("뱀파이어");
    }

    @Override
    void move() {
        System.out.println("밤에만 움직인다.");
        System.out.println("- 천천히 접근한다.");
    }
}


class Jiangshi extends Monster {
    Jiangshi() {
        super("강시");
    }

    @Override
    void move() {
        System.out.println("두 팔을 들고 앞으로 점프하며 이동한다.");
    }
}


class Ghost extends Monster {
    Ghost() {
        super("처녀귀신");
    }

    @Override
    void move() {
        System.out.println("공중을 부드럽게 떠다닌다.");
    }
}


public class MonsterWorld3 {
    public static void main(String[] args) {
        Monster[] monsters = {
            new Zombie(),
            new Vampire(),
            new Jiangshi(),
            new Ghost()
        };

        for (Monster m : monsters) {
            m.display(); // 공통 동작
            m.move();    // 각자의 고유 동작
            System.out.println();
        }
    }
}
