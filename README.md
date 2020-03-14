<h1 align="center">ReUse</h1>

<p align="center">
React Reason components <3 [Storybook](https://bs-reuse.now.sh)
</p>

## Installation
ReUse is available as an npm package.

```sh
// with npm
npm install bs-reuse

// with yarn
yarn add bs-reuse
```

## Usage

```reason
[@react.component]
let make = () => {
  <ReUse.Button onClick=(_ => Js.alert("Hey there!"))>
    {"Hello world!" -> React.string}
  </ReUse.Button>
}
```

## ToDo

[] Modal Component
[] Card Component
[] Custom class on components
[] linter
[] prettier
[] lint-staged
