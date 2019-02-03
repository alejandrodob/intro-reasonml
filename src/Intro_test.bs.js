// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Jest = require("@glennsl/bs-jest/src/jest.js");
var Block = require("bs-platform/lib/js/block.js");
var $$String = require("bs-platform/lib/js/string.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");

describe("Basic types", (function () {
        describe("Booleans", (function () {
                Jest.test("negation", (function (param) {
                        return Jest.Expect[/* toBe */2](false, Jest.Expect[/* expect */0](false));
                      }));
                Jest.test("and", (function (param) {
                        return Jest.Expect[/* toBe */2](false, Jest.Expect[/* expect */0](false));
                      }));
                return Jest.test("or", (function (param) {
                              return Jest.Expect[/* toBe */2](false, Jest.Expect[/* expect */0](false));
                            }));
              }));
        describe("Strings and Chars", (function () {
                Jest.test("String concatenation", (function (param) {
                        return Jest.Expect[/* toBe */2]("abcabc", Jest.Expect[/* expect */0]("abcabc"));
                      }));
                Jest.test("multiline strings", (function (param) {
                        return Jest.Expect[/* toBe */2]("abc\nabc", Jest.Expect[/* expect */0]("abc\nabc"));
                      }));
                Jest.test("String length", (function (param) {
                        return Jest.Expect[/* toBe */2](3, Jest.Expect[/* expect */0](3));
                      }));
                Jest.test("char from string", (function (param) {
                        return Jest.Expect[/* toBe */2](/* "b" */98, Jest.Expect[/* expect */0](/* "b" */98));
                      }));
                return Jest.test("string from char", (function (param) {
                              return Jest.Expect[/* toBe */2]("a", Jest.Expect[/* expect */0]($$String.make(1, /* "a" */97)));
                            }));
              }));
        describe("Integers", (function () {
                Jest.test("addition", (function (param) {
                        return Jest.Expect[/* toBe */2](7, Jest.Expect[/* expect */0](7));
                      }));
                Jest.test("subtraction", (function (param) {
                        return Jest.Expect[/* toBe */2](-1, Jest.Expect[/* expect */0](-1));
                      }));
                Jest.test("product", (function (param) {
                        return Jest.Expect[/* toBe */2](15, Jest.Expect[/* expect */0](15));
                      }));
                Jest.test("division", (function (param) {
                        return Jest.Expect[/* toBe */2](3, Jest.Expect[/* expect */0](3));
                      }));
                return Jest.test("mod", (function (param) {
                              return Jest.Expect[/* toBe */2](1, Jest.Expect[/* expect */0](1));
                            }));
              }));
        describe("Floats", (function () {
                Jest.test("addition", (function (param) {
                        return Jest.Expect[/* toBe */2](7, Jest.Expect[/* expect */0](2 + 5));
                      }));
                Jest.test("subtraction", (function (param) {
                        return Jest.Expect[/* toBe */2](-1, Jest.Expect[/* expect */0](3 - 4));
                      }));
                Jest.test("product", (function (param) {
                        return Jest.Expect[/* toBe */2](15, Jest.Expect[/* expect */0](3 * 5));
                      }));
                Jest.test("division", (function (param) {
                        return Jest.Expect[/* toBe */2](3.5, Jest.Expect[/* expect */0](7 / 2));
                      }));
                return Jest.test("exp", (function (param) {
                              return Jest.Expect[/* toBe */2](4, Jest.Expect[/* expect */0](Math.pow(2, 2)));
                            }));
              }));
        describe("unit", (function () {
                Jest.test("equal to itself", (function (param) {
                        return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](true));
                      }));
                return Jest.test("equal to itself", (function (param) {
                              return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](true));
                            }));
              }));
        return /* () */0;
      }));

describe("Equality", (function () {
        Jest.test("Structural(==): tuples", (function (param) {
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](Caml_obj.caml_equal(/* tuple */[
                                    1,
                                    "abc"
                                  ], /* tuple */[
                                    1,
                                    "abc"
                                  ])));
              }));
        Jest.test("Structural(==): nested tuples", (function (param) {
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](Caml_obj.caml_equal(/* tuple */[
                                    1,
                                    /* tuple */[
                                      "abc",
                                      "abc"
                                    ]
                                  ], /* tuple */[
                                    1,
                                    /* tuple */[
                                      "abc",
                                      "abc"
                                    ]
                                  ])));
              }));
        Jest.test("Structural(==): records", (function (param) {
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](Caml_obj.caml_equal(/* record */[
                                    /* x */2,
                                    /* y */3
                                  ], /* record */[
                                    /* x */2,
                                    /* y */3
                                  ])));
              }));
        Jest.test("Structural(==): recursive data structures", (function (param) {
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](Caml_obj.caml_equal(/* Node */Block.__(0, [
                                      2,
                                      /* Node */Block.__(0, [
                                          1,
                                          /* Leaf */Block.__(1, [5]),
                                          /* Leaf */Block.__(1, [9])
                                        ]),
                                      /* Leaf */Block.__(1, [3])
                                    ]), /* Node */Block.__(0, [
                                      2,
                                      /* Node */Block.__(0, [
                                          1,
                                          /* Leaf */Block.__(1, [5]),
                                          /* Leaf */Block.__(1, [9])
                                        ]),
                                      /* Leaf */Block.__(1, [3])
                                    ]))));
              }));
        Jest.test("Referential(===) 1", (function (param) {
                var myTuple = /* tuple */[
                  1,
                  "abc"
                ];
                return Jest.Expect[/* toBe */2](true, Jest.Expect[/* expect */0](myTuple === myTuple));
              }));
        return Jest.test("Referential(===) 2", (function (param) {
                      return Jest.Expect[/* toBe */2](false, Jest.Expect[/* expect */0](/* tuple */[
                                      1,
                                      "abc"
                                    ] === /* tuple */[
                                      1,
                                      "abc"
                                    ]));
                    }));
      }));

/*  Not a pure module */
