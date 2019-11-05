import React from 'react';

//import {HttpConnection, TJSONProtocol} from './thrift.js';
//import HelloClient from './gen-js/Hello.js';

class App extends React.Component {
    constructor(props) {
	super(props);
	this.state = {greeting: 'none', greeting2: '--'};
	this.onClickClear = this.onClickClear.bind(this);
	this.onClickReq = this.onClickReq.bind(this);
    }

    componentDidMount() {
	let transport = new Thrift.TXHRTransport('http://localhost:9090', {'customHeaders': {}});
	//let transport = new Thrift.TWebSocketTransport('http://localhost:9090');
	//transport = TTransport.TBufferedTransport(transport);
	let protocol = new Thrift.TJSONProtocol(transport);
	let client = new HelloClient(protocol);
	transport.open();
	client.sayHello().then((res) => {
	    console.log("server said: ", res);
	    this.setState({greeting: res, greeting2: 'got it'});
	});
	transport.close();
    }

    onClickClear() {
	this.setState({greeting: 'none', greeting2: '--'});
    }

    onClickReq() {
	let transport = new Thrift.TXHRTransport('http://localhost:9090', {'customHeaders': {}});
	//let transport = new Thrift.TWebSocketTransport('http://localhost:9090');
	//transport = TTransport.TBufferedTransport(transport);
	let protocol = new Thrift.TJSONProtocol(transport);
	let client = new HelloClient(protocol);
	transport.open();
	client.sayHello().then((res) => {
	    console.log("server said: ", res);
	    this.setState({greeting: res, greeting2: 'got it again'});
	});
	transport.close();
    }	
    
    render() {
	return (<div>
		<h1>Hello from modules</h1>
		<h2>{this.state.greeting}</h2>
		<h2>{this.state.greeting2}</h2>
		<button onClick={this.onClickClear}>CLEAR</button>
		<button onClick={this.onClickReq}>REQ</button>
		</div>);
    }
};

export default App;
