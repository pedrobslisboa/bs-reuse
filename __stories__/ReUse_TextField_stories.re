open BsStorybook.Story;
open ReUse;
module Styles = {
  /* Open the Css module, so we can access the style properties below without prefixing them with Css. */
  open Css;

  let inputsWrapper = style([display(`flex), marginBottom(px(40)), marginTop(px(10))]);
  let textField = style([padding2(~v=px(0), ~h=px(10))]);
};

let _module = [%bs.raw "module"];

storiesOf("Elements | Text Field", _module)
->(
    add("default", () =>
      <div>
        <strong> "Labeled"->React.string </strong>
        <div className=Styles.inputsWrapper>
          <TextField className=Styles.textField label="Default" placeholder="Default" />
          <TextField className=Styles.textField label="Default Invalid" valid=false placeholder="Default invalid" />
          <TextField className=Styles.textField label="Outlined" variant=`outlined placeholder="Outline invalid" />
          <TextField
            className=Styles.textField
            label="Error"
            variant=`outlined
            valid=false
            placeholder="Outline invalid"
          />
        </div>
        <strong> "Without label"->React.string </strong>
        <div className=Styles.inputsWrapper>
          <TextField className=Styles.textField placeholder="Without label" />
          <TextField className=Styles.textField valid=false placeholder="Without label invalid" />
          <TextField className=Styles.textField variant=`outlined placeholder="Without label outline" />
          <TextField
            className=Styles.textField
            variant=`outlined
            valid=false
            placeholder="Without label outline invalid"
          />
        </div>
      </div>
    )
  )
->(
    add("filled", () =>
      <div>
        <strong> "Labeled"->React.string </strong>
        <div className=Styles.inputsWrapper>
          <TextField className=Styles.textField filled=true label="Filled" placeholder="Filled" />
          <TextField
            className=Styles.textField
            valid=false
            filled=true
            label="Filled Invalid"
            placeholder="Filled invalid"
          />
          <TextField
            className=Styles.textField
            variant=`outlined
            filled=true
            label="Filled Outline"
            placeholder="Filled Outline"
          />
          <TextField
            className=Styles.textField
            variant=`outlined
            valid=false
            filled=true
            label="Filled Outline invalid"
            placeholder="Filled Outline invalid"
          />
        </div>
        <strong> "Without label"->React.string </strong>
        <div className=Styles.inputsWrapper>
          <TextField className=Styles.textField filled=true placeholder="Filled" />
          <TextField className=Styles.textField valid=false filled=true placeholder="Filled invalid" />
          <TextField className=Styles.textField variant=`outlined filled=true placeholder="Filled Outline" />
          <TextField
            className=Styles.textField
            variant=`outlined
            valid=false
            filled=true
            placeholder="Filled Outline invalid"
          />
        </div>
      </div>
    )
  );
