### 寻求一个跨平台编译环境

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



