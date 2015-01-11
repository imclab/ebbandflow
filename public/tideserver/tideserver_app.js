
var App = {
	
	defaultParams: {
            station: 'sandyhook_nj'
          },

	socket: null,

	endpoints: {
		'sandyhook_nj': 'localhost:80/sandyhook_nj',
		'village_cove_alaska': 'localhost:80/village_cove_alaska',
		'nikika_alaska': 'localhost:80/nikika_alaska',
		'key_west_fl': 'localhost:80/key_west_fl',
		'honolulu_hi': 'localhost:80/honolulu_hi',
		'seattle_wa': 'localhost:80/seattle_wa',
		'pt_reyes_ca': 'localhost:80/pt_reyes_ca'
	},

	init: function() {
		var _this = this;

		console.log('app initiated');
		
		this.changeOptions(this.defaultParams); //set up default form parameters  
		
		this.changeSocket(App.endpoints[this.defaultParams.station]);  //change socket to default params

		this.getRealtimeWaterlevel();  //listens for incoming data

		$('input[name=submit]').click(function(){		//on form submit
	        
	        var formData = {
	            station: inputForm.stationLocation.value     
	        };

	        _this.changeOptions(formData);
	        
	        _this.changeSocket(App.endpoints[formData.station]);
	        
	    });


	},

	getRealtimeWaterlevel: function() {
	    var socket = io('http://localhost:80');

	    socket.on('realtimeWaterLevel', function(data) {
			var d = JSON.parse(data);
			var obj = {
				station: d.metadata.name,
				waterLevel: d.data[0].v
			}

			console.log(obj.station + ': ' + ' ' + obj.waterLevel);
		
		});

	},

	changeOptions: function(obj) {

		$.ajax({
			// url: 'http://localhost:1337/api/changeParameters',
			url: 'http://localhost:80/api/changeParameters',
			type: 'POST',
			dataType: 'JSON',
			data: {
				station: obj.station
			},
		})
		.done(function() {
			console.log("success");
		})
		.fail(function() {
			console.log("error");
		})
		.always(function() {
			console.log("complete");
		});

	},

	changeSocket: function(endpoint) {
		var _this = this;

		if(this.socket) {
			this.socket.removeListener('data');
			this.socket.disconnect('data');
		}

		var socket = io(endpoint, {
			'force new connection': true,
		});

		socket.on('data', function (data) {
	    	var d = JSON.parse(data);
			_this.processData(data);

			socket.on('disconnect', function (socket) {
		  		console.log('disconnected');
		  	});

		});

		this.socket = socket;

	},

	processData: function(data) {
		var d = JSON.parse(data);

		var dataset = [];

		var station = d.metadata.name,
			id = d.metadata.id,
			lat = parseFloat(d.metadata.lat),
			lon = parseFloat(d.metadata.lon);

		for(i = 0; i < d.data.length; i++) {
			var obj = {
					station: station,
					id: id,
					lat: lat,
					lon: lon,
					time: d.data[i].t,
					seaLevel: parseFloat(d.data[i].v),
					f: d.data[i].f, 
					q: d.data[i].q,
					s: d.data[i].s
				}

			if(isNaN(obj.seaLevel) == true) {
				console.log('object ' + i + ' is NaN');
				obj.seaLevel = dataset[i - 1].seaLevel;
			}
			
			dataset.push(obj); 
		}

		this.renderScatterPlot(dataset);
	},

	renderScatterPlot: function(data) {
	      w = $("#scatterPlot").width();
	      h = $("#scatterPlot").height();
	      
	      d3.select("#scatterPlot").selectAll("svg").remove();
	      
	      svg = d3.select("#scatterPlot")
	            .append("svg")
	            .attr("width", w)
	            .attr("height", h);

	      var dataset = data;
	      var last = dataset.length - 1;
	      var _this = this;
	      var padding = 40;

	      var xScale = d3.time.scale()
	                     .domain([new Date(dataset[0].time), new Date(dataset[last].time)])
	                     .range([padding, w - padding]);

	      var yScale = d3.scale.linear()
	                     .domain([d3.min(dataset, function(d) {
	                        return d.seaLevel;
	                     }), d3.max(dataset, function(d) { 
	                        return d.seaLevel; 
	                      })])
	                     .range([h - padding, padding]);

	      //define X Axis
	      var xAxis = d3.svg.axis()
	                  .scale(xScale)
	                  .orient("bottom")
	                  .ticks(5);

	      //define Y Axis
	      var yAxis = d3.svg.axis()
	                  .scale(yScale)
	                  .orient("left")
	                  .ticks(5);

	      //add the circle plot
	      svg.selectAll("circle")
	       .data(dataset)
	       .enter()
	       .append("circle")
	       .attr('class', 'plotPoints')
	       .attr("cx", function(d, i) {
	            d.time = _this.formatDate(d.time);
	            return xScale(d.time); 
	        })
	       .attr("cy", function(d) {
	            return yScale(d.seaLevel); 
	        })
	       .attr("r", function(d) {
	            return 2; 
	        });

	      //add the X axis
	      svg.append("g")
	      .attr("class", "axis")
	      .attr("transform", "translate(0," + (h - padding) + ")")
	      .call(xAxis);

	      //add the Y axis
	      svg.append("g")
	          .attr("class", "axis")
	          .attr("transform", "translate(" + padding + ", 0)")
	          .call(yAxis);         
	    },

	    formatDate: function(date) {
	      var newDate = new Date(date);
	      return newDate; 
	    },

};

App.init();
