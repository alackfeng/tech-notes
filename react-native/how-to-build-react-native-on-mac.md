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

Android环境安装：

> **jdk8：**
>
> brew tap caskroom/versions
>
> brew cask search java8
>
> brew cask install java8
>
> javac -version
>
> **android-studio:**
>
> wget [https://developer.android.com/studio/index.html\#mac-bundle](https://developer.android.com/studio/index.html#mac-bundle)
>
> **env：vi ~/.bash\_profile**
>
> export ANDROID\_HOME=$HOME/Library/Android/sdk
>
> export PATH=$PATH:$ANDROID\_HOME/tools
>
> export PATH=$PATH:$ANDROID\_HOME/platform-tools

### 测试安装

react-native init AwesomeProject   \#react-native init AwesomeProject --version 0.39.2

cd AwesomeProject/

react-native run-ios

### 修改入口文件：

```
vi /Users/taurusfeng/source/code/TarotApp/android/app/build.gradle =>
entryFile: "index.android.js"
```

### 遇到问题：

### Q1. xcrun: error: unable to find utility "instruments", not a developer tool or in PATH

A1. 安装xcode并执行 .  sudo xcode-select -s /Applications/Xcode.app/Contents/Developer/

Q2. 'boost/iterator/iterator\_adaptor.hpp' file not found

A2. yarn upgrade react-native upgrade

Q3. no bundle url present

A3. 取消本机的全局代理模式即可，网络路由问题

Q4. React Native unable to load script from assets index.android.bundle

A4. mkdir -p android/app/src/main/assets;

react-native bundle --platform android --dev false --entry-file index.js --bundle-output android/app/src/main/assets/index.android.bundle --assets-dest

