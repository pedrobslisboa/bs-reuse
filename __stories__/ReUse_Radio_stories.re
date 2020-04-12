open BsStorybook.Story;
open ReUse;
module Styles = {
  /* Open the Css module, so we can access the style properties below without prefixing them with Css. */
  open Css;

  let inputsWrapper = style([marginBottom(px(40)), marginTop(px(10))]);
  let radio = style([marginBottom(px(10)), marginTop(px(10))]);
};

let _module = [%bs.raw "module"];

storiesOf("Elements | Radio", _module)
->(
    add("default", () =>
      <div>
        <div className=Styles.inputsWrapper>
          <Radio.Group onChange={value => Js.log(value)} value="khruangbin">
            <Radio.Button className=Styles.radio value="khruangbin" label="Khruangbin" />
            <Radio.Button className=Styles.radio value="men-i-trust" label="Men I Trust" />
            <Radio.Button className=Styles.radio value="kiko-dinucci" label="Kiko Dinucci" />
          </Radio.Group>
        </div>
      </div>
    )
  );
