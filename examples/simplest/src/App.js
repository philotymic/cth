import React from 'react';

//import {HttpConnection, TJSONProtocol} from './thrift.js';
//import HelloClient from './gen-js/Hello.js';

class App extends React.Component {
    constructor(props) {
	super(props);
	this.transport = new Thrift.TWebSocketTransport('ws://localhost:8888/thrift');
	this.protocol = new Thrift.TJSONProtocol(this.transport);
	this.client = new HelloClient(this.protocol);
	
	this.state = {greeting: 'none', greeting2: '--'};
	this.onClickClear = this.onClickClear.bind(this);
	this.onClickReq = this.onClickReq.bind(this);
	this.close_ws = this.close_ws.bind(this);
    }

    componentDidMount() {
	this.transport.open();
	this.client.sayHello().then((res) => {
	    console.log("server said: ", res);
	    this.setState({greeting: res, greeting2: 'got it'});
	});
    }

    onClickClear() {
	this.setState({greeting: 'none', greeting2: '--'});
    }

    onClickReq() {
	this.client.sayHello().then((res) => {
	    console.log("server said: ", res);
	    this.setState({greeting: res, greeting2: 'got it again'});
	});
    }	

    close_ws() {
	this.transport.close();
	console.log("ws closed");
    }
    
    render() {
	return (<div>
		<h1>Hello from modules</h1>
		<h2>{this.state.greeting}</h2>
		<h2>{this.state.greeting2}</h2>
		<button onClick={this.onClickClear}>CLEAR</button>
		<button onClick={this.onClickReq}>REQ</button>
		<button onClick={this.close_ws}>CLOSE</button>
		</div>);
    }
};

export default App;
