

#####


#### 编写基于EOS的Dapp（react-native使用eosjs）
`````

###### 1. 创建react-native工程 Pecker

react-native init Pecker
yarn install
react-native start
react-native run-ios

or 

npm install -g expo-cli
expo-cli init Pecker
yarn install
yarn start


###### 2. 导入eosjs库

yarn add https://github.com/alackfeng/eosjs.git

###### 3. 增加其余依赖库
yarn add react-native-crypto
yarn add react-native-randombytes
react-native link react-native-randombytes

yarn add tradle/rn-nodeify --dev
./node_modules/.bin/rn-nodeify --hack --install
yarn install

"postinstall": "rn-nodeify --install events,buffer,crypto,stream,util,process,vm --hack",

vi index.js ======>>>>>

// index.ios.js or index.android.js
// make sure you use `import` and not require!  
import './shim.js'
import crypto from 'crypto'
// ...the rest of your code

import {AppRegistry} from 'react-native';
import App from './App';
import {name as appName} from './app.json';

AppRegistry.registerComponent(appName, () => App);

<<<<======

vi package.json ======>>>


"postinstall": "rn-nodeify --install buffer,crypto,stream,util,process,vm --hack",

<<<=====

###### 4. 运行项目

react-native start
react-native run-ios

`````



#### RN集成功能
`````

###### 1. 导航
yarn add react-navigation

`````


#### 问题集锦
`````

问题1: [15:36:54] /Users/tokenfun/source/chick-peck/Pecker/node_modules/eosjs/dist/index.js: Couldn't find preset "env" relative to directory "/Users/tokenfun/source/chick-peck/Pecker/node_modules/eosjs"


[15:43:45] /Users/tokenfun/source/chick-peck/Pecker/node_modules/eosjs/dist/index.js: Couldn't find preset "stage-1" relative to directory "/Users/tokenfun/source/chick-peck/Pecker/node_modules/eosjs"


/Users/tokenfun/source/chick-peck/Pecker/node_modules/eosjs-ecc/lib/index.js: Couldn't find preset "es2015" relative to directory "/Users/tokenfun/source/chick-peck/Pecker/node_modules/eosjs-ecc"

[15:49:42] The package at "node_modules/eosjs-ecc/lib/key_utils.js" attempted to import the Node standard library module "assert". It failed because React Native does not include the Node standard library. Read more at https://docs.expo.io/versions/latest/introduction/faq.html#can-i-use-nodejs-packages-with-expo

[15:52:36] The package at "node_modules/ripemd160/index.js" attempted to import the Node standard library module "buffer". It failed because React Native does not include the Node standard library. Read more at https://docs.expo.io/versions/latest/introduction/faq.html#can-i-use-nodejs-packages-with-expo

解决1: 
yarn add https://github.com/alackfeng/eosjs.git
yarn add babel-core babel-cli babel-preset-env babel-preset-stage-1 babel-preset-es2015
yarn add assert buffer stream events readable-stream 

yarn add babel-plugin-rewrite-require
yarn add stream
yarn add react-native-stream
yarn add stream-browserify
yarn add readable-stream 


问题2: undefined is not an object (evaluating 'superctor.prototype')
解决2: 
###yarn add babel-plugin-rewrite-require
###yarn add readable-stream; cp -rf node_modules/readable-stream/ node_modules/stream/
yarn add react-native-stream; cp -rf node_modules/react-native-stream/ node_modules/stream


问题3: Secure random number generation is not supported by this browser
解决3: https://github.com/tradle/react-native-crypto

yarn add react-native-crypto
yarn add react-native-randombytes
react-native link react-native-randombytes

yarn add tradle/rn-nodeify --dev
./node_modules/.bin/rn-nodeify --hack --install

package.json ===>
"scripts": {
    "postinstall": "rn-nodeify --install events,buffer,crypto,stream,util,process,vm --hack",
    "start": "node node_modules/react-native/local-cli/cli.js start",
    "test": "jest"
  },
  

// index.ios.js or index.android.js
// make sure you use `import` and not require!  
import './shim.js'
import crypto from 'crypto'
// ...the rest of your code



问题4: undefined is not an object (evaluating 'RNRandomBytes.seed') 
解决4: 暂时不能使用expo等，只能用原生的reactnative工程


问题5: Unhandled JS Exception: Could not get BatchedBridge, make sure your bundle is packaged correctly
解决5: 关闭RN start cli，重新启动RN



`````
