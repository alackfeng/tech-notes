[https://github.com/necolas/react-native-web/blob/master/docs/guides/getting-started.md](https://github.com/necolas/react-native-web/blob/master/docs/guides/getting-started.md)

### 安装依赖

```
yarn add react react-dom react-native-web
yarn add --dev webpack webpack-dev-server
yarn add --dev babel-loader url-loader babel-preset-react babel-preset-es2015
yarn add --dev babel-cli babel-core babel-loader babel-preset-es2015 babel-preset-react babel-preset-stage-0 
yarn add --dev babel-plugin-transform-react-remove-prop-types babel-plugin-transform-react-constant-elements babel-plugin-transform-react-inline-elements babel-plugin-array-includes
```

### 配置 WEBPACK.CONFIG.JS

### 运行

```
./node_modules/.bin/webpack-dev-server -d --config ./web/webpack.config.js --inline --hot --colors
```

```
./node_modules/.bin/webpack -p --config ./web/webpack.config.js
```

### 扩展：

```
yarn add babel-runtime
yarn add --dev babel-plugin-transform-runtime
```



