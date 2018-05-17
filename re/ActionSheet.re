[@bs.module "@expo/react-native-action-sheet"]
external connectActionSheet : ReasonReact.reactClass => ReasonReact.reactClass =
  "connectActionSheet";

type showActionSheetWithOptions =
[@bs] (
    {. "options": array(string), "cancelButtonIndex": int, "destructiveButtonIndex": int},
    int => unit
  ) =>
  unit;

let component = ReasonReact.statelessComponent("ActionSheetProvider");

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

let make' = (~showActionSheetWithOptions, children) => {
  ...component,
  render: (_self) =>
    children(
      ~showActionSheetWithOptions=handleShowActionSheetWithOptions(showActionSheetWithOptions)
    )
};

let jsComponent =
  ReasonReact.wrapReasonForJs(
    ~component,
    (props) =>
      make'(~showActionSheetWithOptions=props##showActionSheetWithOptions, props##children)
  );

let enhanced = connectActionSheet(jsComponent);

let make = (children) => {
  ReasonReact.wrapJsForReason(~reactClass=enhanced, ~props=Js.Obj.empty(), children)
};
