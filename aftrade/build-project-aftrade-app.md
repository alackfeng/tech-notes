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

#### 开发日志：

```
1. 通过react-nativee-cli及webpack创建react-native(ios|android)、react-native-web(web)工程aftrade，
2. 增加redux支持，中间件日志／异步操作等 logger promise array to middleware。npm install --save redux-logger
3. 增加启动屏(launch screen)功能，友好于用户(未完成)。1)APP启动时显示，2)js bundle加载并渲染完成后消失，3)全屏显示，4)显示的内容可配置
4. Splash Screen启动页测试
5. 增加Playground测试UI View接口
6. 增加react-navigation导航支持。引导导航StackNavigator及主导航TabNavigator
7. reselect改善react/redux性能（未实现）
8. 增加国际化处理（I18n）react-native-i18n
9. 增加跨平台storage存储（未实现）
10.增加styled-components UI库使用
```

#### react-navigation导航构建：

```
1. 分三部分：StackNavigator顶部导航，TabNavigator底部标签栏，DrawerNavigator侧滑页面
2. screenProps：属于navigationOptions的一个属性，可以全局控制navigationOptions中的某些值，
   比如说你想做换肤功能，修改这个属性绝对是最简单的方式。
3. Linking使用 react-native
4. path属性适用于其他app或浏览器使用url打开本app并进入指定页面。path属性用于声明一个界面路径，例如：【/pages/Home】。
   此时我们可以在手机浏览器中输入：app名称://pages/Home来启动该App，并进入Home界面。
```

#### 增加日志功能：

```
npm install --save redux-logger
```

#### 解决绝对路径访问自定义模块

```
npm install --save-dev babel-plugin-module-resolver
FAQ.
```

    Q1. Uncaught TypeError: Cannot assign to read only property 'exports' of object '#<Object>'
    A1. 因为webpack 2中不允许混用import和module.exports ,
    解决办法就是统一改成ES6的方式编写即可.

    Q2. warning.js?6327:33 Warning: React does not recognize the `headerMode` prop on a DOM element
    A2. StackNavigator({}, {headerMode: 'none'})

    Q3. Uncaught (in promise) Unsupported platform .      @createNavigationContainer.js
    A3. 

    Q4. Unable to resolve module `stream` from `/Users/assetfun/source/code/aftradeapp/node_modules/cipher-base/index.js`
    A4. ----不使用了，npm install stream --save
    npm install --save react-native-stream
    mv node_modules/react-native-stream node_modules/stream


    Q5. Can't find variable: Buffer
    A5. npm install --save buffer
    var Buffer = require('buffer').Buffer;
    if(typeof global !== 'undefined') {
      global.Buffer = require('buffer').Buffer; // TODO just use global Buffer
    }
    npm install --save assetfunjs-ws assetfunjs

    Q6. undefined is not an object (evaluating 'superCtor.prototype')
    A6. 



