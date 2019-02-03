open Jest;
open Expect;
type point = {
  x: int,
  y: int,
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

describe("Equality", () => {
  test("Structural(==): tuples", () =>
    expect((1, "abc") == (1, "abc")) |> toBe(true)
  );

  test("Structural(==): nested tuples", () =>
    expect((1, ("abc", "abc")) == (1, ("abc", "abc"))) |> toBe(true)
  );

  test("Structural(==): records", () =>
    expect({x: 2, y: 3} == {x: 2, y: 3}) |> toBe(true)
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