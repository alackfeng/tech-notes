```
寻求一个跨平台编译环境
```

### [https://github.com/c-h-/universal-native-boilerplate](https://github.com/c-h-/universal-native-boilerplate)

关键字：[react](https://github.com/topics/react)  [react-native](https://github.com/topics/react-native)   [android](https://github.com/topics/android) . [windows](https://github.com/topics/windows) . [ios](https://github.com/topics/ios) .  [macos](https://github.com/topics/macos) . [boilerplate](https://github.com/topics/boilerplate) . [pwa](https://github.com/topics/pwa) . [webpack](https://github.com/topics/webpack) .  [server-side-rendering](https://github.com/topics/server-side-rendering)

项目动机：[https://medium.com/@chulcher/better-apps-by-default-f5a77ca4b9fb](https://medium.com/@chulcher/better-apps-by-default-f5a77ca4b9fb)

编译安装：

```
 mkdir -p ~/source/code/cross-platform-app
 cd ~/source/code/cross-platform-app
 git clone https://github.com/c-h-/universal-native-boilerplate.git cross-platform-app
 cd cross-platform-app
 npm install
 npm run setup # initializes a new git repository
```

常见命令：

```
# Enable a platform or feature
gulp enable windows

# Build a platform
gulp build android # Build debug
gulp build android --production # Build a production version

# Run a platform
gulp run ios # Run debug
gulp run android -p # Run production

# Analyse bundle contents, load speed, and usability
gulp analyze web
```

IOS平台试水：

```
gulp enable ios
gulp build ios
gulp run ios
```

遇到问题：

```
Q1. ../node_modules/react-native/packager/react-native-xcode.sh: No such file or directory
A1. xcode => Build Phases > Bundle React Native code and images
=> export NODE_BINARY=node
../node_modules/react-native/scripts/react-native-xcode.sh

Q2. Error:Unsupported method: BaseConfig.getApplicationIdSuffix().
The version of Gradle you connect to does not support that method.
To resolve the problem you can change/upgrade the target version of Gradle you connect to.
Alternatively, you can ignore this exception and read other information from the model.

Consult IDE log for more details (Help | Show Log)

A2. https://developer.android.com/studio/build/gradle-plugin-3-0-0-migration.html

Q3. Print: Entry, ":CFBundleIdentifier", Does Not Exist
A3.

Q4. com.android.ddmlib.InstallException: INSTALL_FAILED_USER_RESTRICTED: Install canceled by user
A4. 权限问题-mi5 => 设置 - 更多设置 - 开发者选项 - USB安装

Q5. Failed to create provisioning profile.
The app ID "org.reactjs.native.example.TarotApp" cannot be registered to your development team. Change your bundle identifier to a unique string to try again.
A5.
```



