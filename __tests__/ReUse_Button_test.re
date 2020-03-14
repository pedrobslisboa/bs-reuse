/* Component_test.re */

open Jest;
open Expect;
open JestDom;
open ReactTestingLibrary;

describe("getByText", () => {
  test("Component renders", () => {
    let btn = <ReUse_Button> {ReasonReact.string("Hello Button")} </ReUse_Button>;

    btn |> render(_) |> getByText(~matcher=`Str("Hello Button"), _) |> expect |> toBeInTheDocument;
  });

  test("Component renders", () => {
    let btn = <ReUse_Button type_="button" variant=`text> {ReasonReact.string("Hello Button")} </ReUse_Button>;

    btn |> render(_) |> container |> expect |> toMatchSnapshot;
  });

  test("Component renders disabled", () => {
    let onClick = [%raw {|jest.fn()|}];
    let btn =
      <ReUse_Button type_="button" disabled=true onClick> {ReasonReact.string("Hello Button")} </ReUse_Button>
      |> render(_);

    FireEvent.click(btn |> getByText(~matcher=`Str("Hello Button"), _));

    let _ = [%raw {|expect(onClick).not.toHaveBeenCalled()|}];

    pass;
  });

  test("Component onClick prop", () => {
    let onClick = [%raw {|jest.fn()|}];
    let btn =
      <ReUse_Button type_="button" onClick> {ReasonReact.string("Hello Button")} </ReUse_Button> |> render(_);

    FireEvent.click(btn |> getByText(~matcher=`Str("Hello Button"), _));

    let _ = [%raw {|expect(onClick).toHaveBeenCalled()|}];

    pass;
  });
});
