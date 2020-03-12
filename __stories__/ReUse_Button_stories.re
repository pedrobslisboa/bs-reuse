open BsStorybook.Story;
open ReUse;

open Css;

let _module = [%bs.raw "module"];

let root =
    style([
      display(flexBox),
      fontWeight(`num(600)),
      alignItems(center),
      justifyContent(center),
      borderStyle(none),
      padding2(~v=px(8), ~h=px(16)),
      cursor(`pointer),
      borderRadius(px(50)),
      fontFamily(`custom("'Montserrat', sans-serif;")),
      letterSpacing(em(0.02)),
      lineHeight(`abs(1.75)),
      outlineStyle(none),
]);

storiesOf("Elements | ReUse_Button", _module)
->(
    add("default", () =>
      <Button> {ReasonReact.string("DEFAULT")} </Button>
    )
  )
->(
    add("disabled", () => {
      let disabled = true;
        <Button disabled>
          {ReasonReact.string("DISABLE")}
        </Button>;
    })
  )
->(
    add("Text button", () => {
      <div>
        <Button variant=`text>
          {ReasonReact.string("TEXT")}
        </Button>
      </div>
    })
  )
->(
    add("Outlined", () => {
      <div>
        <Button variant=`outline>
          {ReasonReact.string("OUTLINED")}
        </Button>
      </div>
    })
  );