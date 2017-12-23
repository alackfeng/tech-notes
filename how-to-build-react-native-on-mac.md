### 环境搭建

* ### target os: ios
* develop platform: macOS

### 依赖软件：

* HomeBrew：

/usr/bin/ruby -e "$\(curl -fsSL [https://raw.githubusercontent.com/Homebrew/install/master/install\](https://raw.githubusercontent.com/Homebrew/install/master/install%29\)"

* Node：

brew install node

* Yarn、React Native的命令行工具（react-native-cli）

npm install -g yarn react-native-cli

* Watchman

brew install watchman

* Flow

brew install flow

* Xcode

AppStore install

### 测试安装

react-native init AwesomeProject

cd AwesomeProject/

react-native run-ios

Q1. xcrun: error: unable to find utility "instruments", not a developer tool or in PATH

A1. 安装xcode并执行 .  sudo xcode-select -s /Applications/Xcode.app/Contents/Developer/

Q2. 'boost/iterator/iterator\_adaptor.hpp' file not found

A2. yarn upgrade react-native upgrade

Q3. no bundle url present

A3. 取消本机的全局代理模式即可，网络路由问题





