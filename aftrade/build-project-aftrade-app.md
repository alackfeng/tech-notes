```

```

## 构建aftrade平台APP，支持ios\|android\|web\|desktop等多平台

#### 开发环境：

* macos 10.12.6 \(16G29\)

* mac pro

#### 安装依赖：

* android studio
* xcode
* node\|npm\|...
* react\|react-native

#### 源码编译：

```
git clone https://github.com/alackfeng/aftradeapp.git
cd aftradeapp

# android
gulp enable android
gulp build android
gulp run android

# ios
gulp enable ios
gulp build ios
react-native run-ios --device ###gulp run ios

# web
gulp enable web
gulp build web
gulp run web
```

#### 增加日志功能：

```
npm install --save redux-logger
```



