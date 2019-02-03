open Jest;
open Expect;

module Records = {
  type point = {
    x: int,
    y: int,
  };

  type parametrizedPoint('a, 'b) = {
    x: 'a,
    y: 'b,
  };

  type mutablePoint = {
    mutable x: int,
    mutable y: int,
  };
};

type tree('a) =
  | Node('a, tree('a), tree('a))
  | Leaf('a);

describe("Basic types", () => {
  describe("Booleans", () => {
    test("negation", () =>
      expect(!true) |> toBe(false)
    );
    test("and", () =>
      expect(true && false) |> toBe(false)
    );
    test("or", () =>
      expect(false || false) |> toBe(false)
    );
  });

  describe("Strings and Chars", () => {
    test("String concatenation", () =>
      expect("abc" ++ "abc") |> toBe("abcabc")
    );
    test("multiline strings", () =>
      expect("abc
abc") |> toBe("abc\nabc")
    );
    test("String length", () =>
      expect(String.length("abc")) |> toBe(3)
    );
    test("char from string", () =>
      expect("abc".[1]) |> toBe('b')
    );
    test("string from char", () =>
      expect(String.make(1, 'a')) |> toBe("a")
    );
  });

  describe("Integers", () => {
    test("addition", () =>
      expect(2 + 5) |> toBe(7)
    );
    test("subtraction", () =>
      expect(3 - 4) |> toBe(-1)
    );
    test("product", () =>
      expect(3 * 5) |> toBe(15)
    );
    test("division", () =>
      expect(7 / 2) |> toBe(3)
    );
    test("mod", () =>
      expect(7 mod 2) |> toBe(1)
    );
  });

  describe("Floats", () => {
    test("addition", () =>
      expect(2. +. 5.) |> toBe(7.)
    );
    test("subtraction", () =>
      expect(3. -. 4.) |> toBe(-1.)
    );
    test("product", () =>
      expect(3. *. 5.) |> toBe(15.)
    );
    test("division", () =>
      expect(7. /. 2.) |> toBe(3.5)
    );
    test("exp", () =>
      expect(2. ** 2.) |> toBe(4.)
    );
  });

  describe("unit", () => {
    test("equal to itself", () =>
      expect(() == ()) |> toBe(true)
    );
    test("equal to itself", () =>
      expect(() === ()) |> toBe(true)
    );
  });
});

describe("Infix operators", () =>
  test(
    "can be defined (but only with these characters = < > @ ^ | & + - * / $ %)",
    () => {
    let ( *...* ) = (a, b) =>
      "start -> " ++ "here is a: " ++ a ++ "here is b: " ++ b ++ " -> bye";

    expect("a" *...* "b") |> toBe("start -> here is a: ahere is b: b -> bye");
  })
);

describe("Tuples", () => {
  test("can hold heterogeneous data", () =>
    expect((1, "hola")) |> toEqual((1, "hola"))
  );

  test("can be destructured (pattern matched)", () => {
    let (_, (hi, _)) = (1, ("hola", "adios"));
    expect(hi) |> toBe("hola");
  });
});

describe("Lists", () => {
  test("can only hold homogeneous data", () => {
    /* let myList = [1, "1"]; won't compile!! */
    let myList = [1, 2];
    expect(List.length(myList)) |> toBe(2);
  });

  test("can be extended with spread operator", () => {
    let shortList = [1, 2];
    let newList = [1, 2, 3, ...shortList];
    /* let newList1 = [...shortList, ...shortList]; won't compile!! */
    expect(newList) |> toEqual([1, 2, 3, 1, 2]);
  });

  test("can be concatenated with @ operator", () =>
    expect(["a", "b"] @ ["c", "d"]) |> toEqual(["a", "b", "c", "d"])
  );

  test("can be mapped, reduced, etc", () =>
    expect(List.map(a => a + 1, [1, 2, 3])) |> toEqual([2, 3, 4])
  );

  test("can be destructured (pattern matched)", () => {
    let [_, ...rest] = [1, 2];
    expect(rest) |> toEqual([2]);
  });
});

describe("Arrays", () => {
  test("can only hold homogeneous data", () => {
    /* let myArray = [|1, "1"|]; won't compile!! */
    let myArray = [|1, 2|];
    expect(Array.length(myArray)) |> toBe(2);
  });

  test("can be accessed by index with bracket notation", () => {
    let myArray = [|1, 2|];
    expect(myArray[0]) |> toBe(1);
  });

  test("are mutable", () => {
    let myArray = [|1, 2|];
    myArray[0] = 0;
    expect(myArray[0]) |> toBe(0);
  });

  test("can be mapped, reduced, etc", () =>
    expect(Array.map(a => a + 1, [|1, 2, 3|])) |> toEqual([|2, 3, 4|])
  );

  test("can be destructured (pattern matched)", () => {
    let [|first, second|] = [|1, 2|];
    expect([|second, first|]) |> toEqual([|2, 1|]);
  });
});

describe("Records", () => {
  open Records;
  test("allow access to their fields with dot notation", () => {
    let myPoint: point = {x: 4, y: 5};
    expect(myPoint.x) |> toBe(4);
  });

  test("are immutable by default", () => {
    let myPoint: point = {x: 4, y: 5};
    /* The following does not compile */
    /* myPoint.x = 1; */
    expect(myPoint.x) |> toBe(4);
  });

  test("can be made mutable", () => {
    let myPoint: mutablePoint = {x: 4, y: 5};
    myPoint.x = 1;
    expect(myPoint.x) |> toBe(1);
  });

  test("can be parametrized at declaration", () => {
    let myPoint: parametrizedPoint(string, int) = {x: "hola", y: 5};
    expect(myPoint.x) |> toBe("hola");
  });

  test("can be spread to form new records", () => {
    let myPoint: point = {x: 3, y: 5};
    let myNewPoint = {...myPoint, x: 10};
    expect(myNewPoint.x) |> toBe(10);
  });

  test("can be destructured (pattern matched)", () => {
    let myPoint: point = {x: 3, y: 5};
    let {x: xCoord}: point = myPoint;
    expect(xCoord) |> toBe(3);
  });
});

describe("Equality", () => {
  test("Structural(==): tuples", () =>
    expect((1, "abc") == (1, "abc")) |> toBe(true)
  );

  test("Structural(==): nested tuples", () =>
    expect((1, ("abc", "abc")) == (1, ("abc", "abc"))) |> toBe(true)
  );

  test("Structural(==): records", () =>
    Records.(expect({x: 2, y: 3} == {x: 2, y: 3}) |> toBe(true))
  );

  test("Structural(==): recursive data structures", ()
    /* Node(2, Node(1, Leaf(5), Leaf(9)), Leaf(3))
                     2
                   /   \
                  1     3
                 / \
                5   9
       */
    =>
      expect(
        Node(2, Node(1, Leaf(5), Leaf(9)), Leaf(3))
        == Node(2, Node(1, Leaf(5), Leaf(9)), Leaf(3)),
      )
      |> toBe(true)
    );

  test("Referential(===) 1", () => {
    let myTuple = (1, "abc");
    expect(myTuple === myTuple) |> toBe(true);
  });

  test("Referential(===) 2", () =>
    expect((1, "abc") === (1, "abc")) |> toBe(false)
  );
});