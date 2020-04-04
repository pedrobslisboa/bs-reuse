open BsStorybook.Story;
open ReUse;

module Styles = {
  /* Open the Css module, so we can access the style properties below without prefixing them with Css. */
  open Css;

  let buttonsWrapper = style([display(`flex), marginBottom(px(40)), marginTop(px(10))]);
  let button = style([marginRight(px(20))]);
};

let _module = [%bs.raw "module"];

storiesOf("Elements | Button", _module)
->(
    add("default", () =>
      <div className=Styles.buttonsWrapper>
        <Button className=Styles.button> {ReasonReact.string("DEFAULT")} </Button>
        <Button className=Styles.button elevated=true> {ReasonReact.string("ELEVATED")} </Button>
      </div>
    )
  )
->(
    add("disabled", () => {
      let disabled = true;
      let elevated = true;
      <div className=Styles.buttonsWrapper>
        <Button className=Styles.button disabled> {ReasonReact.string("DISABLE")} </Button>
        <Button className=Styles.button elevated disabled> {ReasonReact.string("ELEVATED")} </Button>
      </div>;
    })
  )
->(add("Text button", () => <div> <Button variant=`text> {ReasonReact.string("TEXT")} </Button> </div>))
->(add("Outlined", () => <div> <Button variant=`outlined> {ReasonReact.string("OUTLINED")} </Button> </div>));
