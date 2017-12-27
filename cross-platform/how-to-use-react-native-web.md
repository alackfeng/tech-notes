[https://github.com/necolas/react-native-web/blob/master/docs/guides/getting-started.md](https://github.com/necolas/react-native-web/blob/master/docs/guides/getting-started.md)

### 安装依赖

```
yarn add react react-dom react-native-web
yarn add --dev webpack webpack-dev-server
yarn add --dev babel-loader url-loader babel-preset-react babel-preset-es2015
```

### 配置 WEBPACK.CONFIG.JS

### 运行

```
./node_modules/.bin/webpack-dev-server -d --config ./web/webpack.config.js --inline --hot --colors
```

```
./node_modules/.bin/webpack -p --config ./web/webpack.config.js
```



  


