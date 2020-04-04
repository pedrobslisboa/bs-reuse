'use strict';

var Jest = require("@glennsl/bs-jest/src/jest.js");
var React = require("react");
var JestDom = require("bs-jest-dom/src/JestDom.bs.js");
var ReUse_TextField = require("../src/ReUse_TextField.js");
var ReactTestingLibrary = require("bs-react-testing-library/src/ReactTestingLibrary.bs.js");

Jest.describe("getByText", (function (param) {
        return Jest.test(" if component renders", (function (param) {
                      var btn = React.createElement(ReUse_TextField.make, {
                            label: "Some Label"
                          });
                      var __x = ReactTestingLibrary.render(undefined, undefined, btn);
                      return JestDom.toBeInTheDocument(Jest.Expect.expect(ReactTestingLibrary.getByText(/* `Str */[
                                          4153489,
                                          "Some Label"
                                        ], undefined, __x)));
                    }));
      }));

/*  Not a pure module */
