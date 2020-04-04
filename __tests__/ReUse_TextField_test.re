/* Component_test.re */

open Jest;
open Expect;
open JestDom;
open ReactTestingLibrary;

open ReUse;

describe("getByText", () =>
  test(" if component renders", () => {
    let btn = <TextField label="Some Label" />;

    btn |> render(_) |> getByText(~matcher=`Str("Some Label"), _) |> expect |> toBeInTheDocument;
  })
);
