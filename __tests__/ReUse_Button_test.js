'use strict';

var Jest = require("@glennsl/bs-jest/src/jest.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var JestDom = require("bs-jest-dom/src/JestDom.bs.js");
var ReUse_Button = require("../src/ReUse_Button.js");
var ReactTestingLibrary = require("bs-react-testing-library/src/ReactTestingLibrary.bs.js");

Jest.describe("getByText", (function (param) {
        Jest.test("Component renders", (function (param) {
                var btn = React.createElement(ReUse_Button.make, {
                      children: "Hello Button"
                    });
                var __x = ReactTestingLibrary.render(undefined, undefined, btn);
                return JestDom.toBeInTheDocument(Jest.Expect.expect(ReactTestingLibrary.getByText(/* `Str */[
                                    4153489,
                                    "Hello Button"
                                  ], undefined, __x)));
              }));
        Jest.test("Component renders", (function (param) {
                var btn = React.createElement(ReUse_Button.make, {
                      type_: "button",
                      children: "Hello Button",
                      variant: /* text */-856044371
                    });
                return Jest.Expect.toMatchSnapshot(Jest.Expect.expect(ReactTestingLibrary.render(undefined, undefined, btn).container));
              }));
        Jest.test("Component renders disabled", (function (param) {
                var onClick = (jest.fn());
                var __x = React.createElement(ReUse_Button.make, {
                      onClick: onClick,
                      type_: "button",
                      children: "Hello Button",
                      disabled: true
                    });
                var btn = ReactTestingLibrary.render(undefined, undefined, __x);
                Curry._2(ReactTestingLibrary.FireEvent.click, undefined, ReactTestingLibrary.getByText(/* `Str */[
                          4153489,
                          "Hello Button"
                        ], undefined, btn));
                ((expect(onClick).not.toHaveBeenCalled()));
                return Jest.pass;
              }));
        return Jest.test("Component onClick prop", (function (param) {
                      var onClick = (jest.fn());
                      var __x = React.createElement(ReUse_Button.make, {
                            onClick: onClick,
                            type_: "button",
                            children: "Hello Button"
                          });
                      var btn = ReactTestingLibrary.render(undefined, undefined, __x);
                      Curry._2(ReactTestingLibrary.FireEvent.click, undefined, ReactTestingLibrary.getByText(/* `Str */[
                                4153489,
                                "Hello Button"
                              ], undefined, btn));
                      ((expect(onClick).toHaveBeenCalled()));
                      return Jest.pass;
                    }));
      }));

/*  Not a pure module */
