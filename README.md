# bs-package-boilerplate

[![Greenkeeper badge](https://badges.greenkeeper.io/Astrocoders/bs-package-boilerplate.svg)](https://greenkeeper.io/)
[![Build Status](https://travis-ci.org/Astrocoders/bs-package-boilerplate.svg?branch=master)](https://travis-ci.org/Astrocoders/bs-package-boilerplate)

A BuckleScript NPM package boilerplate

## Install
```
yarn add bs-react-native-action-sheet @expo/react-native-action-sheet
```
And then update your bsconfig.json with it
Also do the normal setup as you would do for the JS one.
Add the ActionSheetProvider somewhere in the top of your components tree.

## Usage
```reason
let component = ReasonReact.statelessComponent("ListItem");
let handlePress = (showActionSheetWithOptions, ()) =>
  showActionSheetWithOptions(
    /* We'll probably make these variants in the next release */
    ~options=["Edit", "Delete", "Cancel"],
    ~destructiveButtonIndex=1,
    ~cancelButtonIndex=2,
    ~callback=
      (buttonIndex) =>
        switch buttonIndex {
        | 0 => ()
        | _ => ()
        }
  );
let make = (~label, ~image, ~onPress=ignore, _children) => {
  ...component,
  render: (_self) =>
    <ActionSheet>
      (
        (~showActionSheetWithOptions) =>
          <Wrapper onPress>
            <HGroup>
              <ListIcon source=image />
              <Text
                ellipsizeMode=`tail
                style=Style.(style([fontSize(15.), marginLeft(20.)]))
                value=label
              />
            </HGroup>
            <TouchableOpacity onPress=(handlePress(showActionSheetWithOptions))>
              <MaterialCommunityIcons name="dots-vertical" color=AppTheme.Colors.greyLight />
            </TouchableOpacity>
          </Wrapper>
      )
    </ActionSheet>
};
```
