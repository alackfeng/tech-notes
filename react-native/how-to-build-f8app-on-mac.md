[https://f8-app.liaohuqiu.net/tutorials/building-the-f8-app/planning/](https://f8-app.liaohuqiu.net/tutorials/building-the-f8-app/planning/)

下载源码

git clone [https://github.com/fbsamples/f8app.git](https://github.com/fbsamples/f8app.git)

cd f8app

## 安装依赖

## 全平台

[Yarn](https://yarnpkg.com/en/docs/install), for installing the NPM dependencies and running helper scripts.

**npm install -g yarn**

[Watchman](https://facebook.github.io/watchman/docs/install.html), for the React Native packager to automatically detect your changes.

**brew install watchman**

[Docker](https://docs.docker.com/engine/installation/), for running the local development server.

**brew cask install docker**

[Docker Compose](https://docs.docker.com/compose/install/), for running the local development server \(included with Docker for Mac and Windows\).

### Android

[Android Studio](https://developer.android.com/studio/install.html), for the Android SDK and tools.

_Make sure to install the SDK and build tools for API level 23 \(see_[_here_](https://facebook.github.io/react-native/docs/getting-started.html)_for more details\)._

### iOS

[Xcode 8.3 +](https://developer.apple.com/download/), for the iOS build toolchain and simulators.

Facebook SDK \([iOS](https://developers.facebook.com/docs/ios/)\), for building Facebook functionality into the app.

wget [https://origincache.facebook.com/developers/resources/?id=facebook-ios-sdk-current.zip](https://origincache.facebook.com/developers/resources/?id=facebook-ios-sdk-current.zip)

mv FacebookSDKs-iOS-4.29.0 ~/Documents/

mv FacebookSDKs-iOS-4.29.0/ FacebookSDK

ls -ltr ~/Documents/FacebookSDK

_Make sure the files are in_`~/Documents/FacebookSDK/`

运行APP

yarn server

yarn

yarn ios

---

相关技术点：

[https://f8-app.liaohuqiu.net/tutorials/building-the-f8-app/planning/](https://f8-app.liaohuqiu.net/tutorials/building-the-f8-app/planning/)

数据存储：Parse Server

错误检测：Flow

单元测试：Jest

app数据后端  Parse Server  and Parse Dashboard





Q1.  **Connection to http://192.168.1.8.xip.io:8081/debugger-proxy?role=client timed out. Are you running node proxy? If you are running on the device**

A1. 

---

代理配置：

git config --global http.proxy [http://](http://192.168.1.12:8888)127.0.0.1:51589

git config --global https.proxy [http://](http://192.168.1.12:8888)127.0.0.1:51589

yarn config set proxy [http://](http://192.168.1.12:8888)127.0.0.1:51589

yarn config set https-proxy [http://](http://192.168.1.12:8888)127.0.0.1:51589

export HTTP\_PROXY="[http://](http://192.168.1.12:8888)127.0.0.1:51589"

export HTTPS\_PROXY="[http://](http://192.168.1.12:8888)127.0.0.1:51589"

[https://f8-app.liaohuqiu.net/\#content](https://f8-app.liaohuqiu.net/#content)

