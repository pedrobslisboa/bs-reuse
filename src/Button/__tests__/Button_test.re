/* Component_test.re */

open Jest;
open Expect;
open JestDom;
open ReactTestingLibrary;

describe("getByText", () => {
    test("Component renders", () =>{
      let btn = (<Button> {ReasonReact.string("Hello Button")} </Button>);

      btn
      |> render
      |> getByText(~matcher=`Str("Hello Button"))
      |> expect
      |> toBeInTheDocument;
    });

    test("Component renders", () =>{
      let btn = (<Button type_="button" variant=`text color=`primary> {ReasonReact.string("Hello Button")} </Button>);

      btn
      |> render
      |> container
      |> expect
      |> toMatchSnapshot;
    });

    test("Component renders disabled", () =>{
      let onClick = [%raw {|jest.fn()|}];
      let btn = (<Button type_="button" onClick> {ReasonReact.string("Hello Button")} </Button> |> render);

      let _ = [%raw {|expect(onClick).not.toHaveBeenCalled()|}];

      pass
    });

    test("Component onClick prop", () =>{
      let onClick = [%raw {|jest.fn()|}];
      let btn = (<Button type_="button" onClick> {ReasonReact.string("Hello Button")} </Button> |> render);

      FireEvent.click(btn |> getByText(~matcher=`Str("Hello Button")));

      let _ = [%raw {|expect(onClick).toHaveBeenCalled()|}];

      pass
    });
});