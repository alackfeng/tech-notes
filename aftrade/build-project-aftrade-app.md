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

#### 开发日志：

```
1. 增加redux中间件日志／异步操作等 logger promise array to middleware
   npm install --save redux-logger
2. 增加启动屏(launch screen)功能，友好于用户(未完成)
   1)APP启动时显示，2)js bundle加载并渲染完成后消失，3)全屏显示，4)显示的内容可配置
3.
```

#### 待完成：

```
1. 增加跨平台storage存储？？？？？
```

#### FAQ.

```
Q1. Uncaught TypeError: Cannot assign to read only property 'exports' of object '#<Object>'
A1. 因为webpack 2中不允许混用import和module.exports ,
解决办法就是统一改成ES6的方式编写即可.

Q2.
A2.
```



