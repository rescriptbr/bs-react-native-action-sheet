[@bs.module "@expo/react-native-action-sheet"]
external connectActionSheet : ReasonReact.reactClass => ReasonReact.reactClass =
  "connectActionSheet";

let component = ReasonReact.statelessComponent("ActionSheetProvider");

type showActionSheetWithOptions =
[@bs] (
    {. "options": array(string), "cancelButtonIndex": int, "destructiveButtonIndex": int},
    int => unit
  ) =>
  unit;

let handleShowActionSheetWithOptions =
    (
      showActionSheetWithOptions: showActionSheetWithOptions,
      ~options: list(string),
      ~destructiveButtonIndex: int,
      ~cancelButtonIndex: int,
      ~callback: int => unit
    ) =>
    [@bs] showActionSheetWithOptions(
    {
      "options": options |> Array.of_list,
      "destructiveButtonIndex": destructiveButtonIndex,
      "cancelButtonIndex": cancelButtonIndex
    },
    callback
  );

let make' = (~showActionSheetWithOptions: showActionSheetWithOptions, children) => {
  ...component,
  render: (_self) =>
    children[0](
      ~showActionSheetWithOptions=handleShowActionSheetWithOptions(showActionSheetWithOptions)
    )
};

let make = (children) => {
  let jsComponent =
    ReasonReact.wrapReasonForJs(
      ~component,
      (props: {. "showActionSheetWithOptions": showActionSheetWithOptions}) =>
        make'(~showActionSheetWithOptions=props##showActionSheetWithOptions, children)
    );
  let enhanced = connectActionSheet(jsComponent);
  ReasonReact.wrapJsForReason(~reactClass=enhanced, ~props=Js.Obj.empty(), [||])
};
