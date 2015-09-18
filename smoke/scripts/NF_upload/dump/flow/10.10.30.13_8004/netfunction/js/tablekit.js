//-------------------------------------------------------------------------------
// To provide the resizable table column in test-run Table

//------------------------------------------------------------------------------
var TableKit = Class.create();

TableKit.prototype = {
	initialize : function(elm, options) {
		var table = $(elm);
		if(table.tagName !== "TABLE") {
			return;
		}
		TableKit.register(table,Object.extend(TableKit.options,options || {}));
		this.id = table.id;
		
		if(op.resizable) {
			TableKit.Resizable.init(table);
		}
		
	},
	
	resizeColumn : function(column, w) {
		TableKit.Resizable.resize(this.id, column, w);
	}
	
};

Object.extend(TableKit, {
	getBodyRows : function(table) {
		table = $(table);
		var id = table.id;
		if(!TableKit.rows[id]) {
			TableKit.rows[id] = (table.tHead && table.tHead.rows.length > 0) ? $A(table.tBodies[0].rows) : $A(table.rows).without(table.rows[0]);
		}
		return TableKit.rows[id];
	},
	getHeaderCells : function(table, cell) {
		if(!table) { table = $(cell).up('table'); }
		var id = table.id;
		if(!TableKit.heads[id]) {
			TableKit.heads[id] = $A((table.tHead && table.tHead.rows.length > 0) ? table.tHead.rows[table.tHead.rows.length-1].cells : table.rows[0].cells);
		}
		return TableKit.heads[id];
	},
	getCellIndex : function(cell) {
		return $A(cell.parentNode.cells).indexOf(cell);
	},
	getRowIndex : function(row) {
		return $A(row.parentNode.rows).indexOf(row);
	},
	getCellText : function(cell, refresh) {
		if(!cell) { return ""; }
		TableKit.registerCell(cell);
		var data = TableKit.cells[cell.id];
		if(refresh || data.refresh || !data.textContent) {
			data.textContent = cell.textContent ? cell.textContent : cell.innerText;
			data.refresh = false;
		}
		return data.textContent;
	},
	register : function(table, options) {
		if(!table.id) {
			TableKit._tblcount += 1;
			table.id = "tablekit-table-" + TableKit._tblcount;
		}
		var id = table.id;
		TableKit.tables[id] = TableKit.tables[id] ? Object.extend(TableKit.tables[id], options || {}) : Object.extend({sortable:false,resizable:false,editable:false}, options || {});
	},
	registerCell : function(cell) {
		if(!cell.id) {
			TableKit._cellcount += 1;
			cell.id = "tablekit-cell-" + TableKit._cellcount;
		}
		if(!TableKit.cells[cell.id]) {
			TableKit.cells[cell.id] = {textContent : '', htmlContent : '', active : false};
		}
	},
	
	isResizable : function(table) {
		return TableKit.tables[table.id] ? TableKit.tables[table.id].resizable : false;
	},
	
	setup : function(o) {
		Object.extend(TableKit.options, o || {} );
	},
	option : function(s, id, o1, o2) {
		o1 = o1 || TableKit.options;
		o2 = o2 || (id ? (TableKit.tables[id] ? TableKit.tables[id] : {}) : {});
		var key = id + s;
		if(!TableKit._opcache[key]){
			TableKit._opcache[key] = $A($w(s)).inject([],function(a,v){
				a.push(a[v] = o2[v] || o1[v]);
				return a;
			});
		}
		return TableKit._opcache[key];
	},
	e : function(event) {
		return event || window.event;
	},
	tables : {},
	_opcache : {},
	cells : {},
	rows : {},
	heads : {},
	options : {
		autoLoad : true,
		stripe : true,
		sortable : true,
		resizable : true,
		editable : true,
		
		resizableSelector : ['table.resizable'],
		minWidth : 10,
		showHandle : true,
		resizeOnHandleClass : 'resize-handle-active',
		
		formClassName : 'editable-cell-form'
	
		
	},
	_tblcount : 0,
	_cellcount : 0,
	load : function() {
		if(TableKit.options.autoLoad) {
			
			if(TableKit.options.resizable) {
				$A(TableKit.options.resizableSelector).each(function(s){
					$$(s).each(function(t) {
						TableKit.Resizable.init(t);
					});
				});
			}
			
		}
	}
});

TableKit.Rows = {
	stripe : function(table) {
		var rows = TableKit.getBodyRows(table);
		rows.each(function(r,i) {
			TableKit.Rows.addStripeClass(table,r,i);
		});
	},
	addStripeClass : function(t,r,i) {
		t = t || r.up('table');
		var op = TableKit.option('rowEvenClass rowOddClass', t.id);
		var css = ((i+1)%2 === 0 ? op[0] : op[1]);
		// using prototype's assClassName/RemoveClassName was not efficient for large tables, hence:
		var cn = r.className.split(/\s+/);
		var newCn = [];
		for(var x = 0, l = cn.length; x < l; x += 1) {
			if(cn[x] !== op[0] && cn[x] !== op[1]) { newCn.push(cn[x]); }
		}
		newCn.push(css);
		r.className = newCn.join(" ");
	}
};

var TableKit = Class.create();

TableKit.prototype = {
	initialize : function(elm, options) {
		var table = $(elm);
		if(table.tagName !== "TABLE") {
			return;
		}
		TableKit.register(table,Object.extend(TableKit.options,options || {}));
		this.id = table.id;
		var op = TableKit.option('sortable resizable editable', this.id);
		if(op.sortable) {
			TableKit.Sortable.init(table);
		} 
		if(op.resizable) {
			TableKit.Resizable.init(table);
		}
		if(op.editable) {
			TableKit.Editable.init(table);
		}
	},
	sort : function(column, order) {
		TableKit.Sortable.sort(this.id, column, order);
	},
	resizeColumn : function(column, w) {
		TableKit.Resizable.resize(this.id, column, w);
	},
	editCell : function(row, column) {
		TableKit.Editable.editCell(this.id, row, column);
	}
};

Object.extend(TableKit, {
	getBodyRows : function(table) {
		table = $(table);
		var id = table.id;
		if(!TableKit.rows[id]) {
			TableKit.rows[id] = (table.tHead && table.tHead.rows.length > 0) ? $A(table.tBodies[0].rows) : $A(table.rows).without(table.rows[0]);
		}
		return TableKit.rows[id];
	},
	getHeaderCells : function(table, cell) {
		if(!table) { table = $(cell).up('table'); }
		var id = table.id;
		if(!TableKit.heads[id]) {
			TableKit.heads[id] = $A((table.tHead && table.tHead.rows.length > 0) ? table.tHead.rows[table.tHead.rows.length-1].cells : table.rows[0].cells);
		}
		return TableKit.heads[id];
	},
	getCellIndex : function(cell) {
		return $A(cell.parentNode.cells).indexOf(cell);
	},
	getRowIndex : function(row) {
		return $A(row.parentNode.rows).indexOf(row);
	},
	getCellText : function(cell, refresh) {
		if(!cell) { return ""; }
		TableKit.registerCell(cell);
		var data = TableKit.cells[cell.id];
		if(refresh || data.refresh || !data.textContent) {
			data.textContent = cell.textContent ? cell.textContent : cell.innerText;
			data.refresh = false;
		}
		return data.textContent;
	},
	register : function(table, options) {
		if(!table.id) {
			TableKit._tblcount += 1;
			table.id = "tablekit-table-" + TableKit._tblcount;
		}
		var id = table.id;
		TableKit.tables[id] = TableKit.tables[id] ? Object.extend(TableKit.tables[id], options || {}) : Object.extend({sortable:false,resizable:false,editable:false}, options || {});
	},
	registerCell : function(cell) {
		if(!cell.id) {
			TableKit._cellcount += 1;
			cell.id = "tablekit-cell-" + TableKit._cellcount;
		}
		if(!TableKit.cells[cell.id]) {
			TableKit.cells[cell.id] = {textContent : '', htmlContent : '', active : false};
		}
	},
	isSortable : function(table) {
		return TableKit.tables[table.id] ? TableKit.tables[table.id].sortable : false;
	},
	isResizable : function(table) {
		return TableKit.tables[table.id] ? TableKit.tables[table.id].resizable : false;
	},
	isEditable : function(table) {
		return TableKit.tables[table.id] ? TableKit.tables[table.id].editable : false;
	},
	setup : function(o) {
		Object.extend(TableKit.options, o || {} );
	},
	option : function(s, id, o1, o2) {
		o1 = o1 || TableKit.options;
		o2 = o2 || (id ? (TableKit.tables[id] ? TableKit.tables[id] : {}) : {});
		var key = id + s;
		if(!TableKit._opcache[key]){
			TableKit._opcache[key] = $A($w(s)).inject([],function(a,v){
				a.push(a[v] = o2[v] || o1[v]);
				return a;
			});
		}
		return TableKit._opcache[key];
	},
	e : function(event) {
		return event || window.event;
	},
	tables : {},
	_opcache : {},
	cells : {},
	rows : {},
	heads : {},
	options : {
		autoLoad : true,
		stripe : true,
		sortable : true,
		resizable : true,
		editable : true,
		rowEvenClass : 'roweven',
		rowOddClass : 'rowodd',
		sortableSelector : ['table.sortable'],
		columnClass : 'sortcol',
		descendingClass : 'sortdesc',
		ascendingClass : 'sortasc',
		noSortClass : 'nosort',
		sortFirstAscendingClass : 'sortfirstasc',
		sortFirstDecendingClass : 'sortfirstdesc',
		resizableSelector : ['table.resizable'],
		minWidth : 10,
		showHandle : true,
		resizeOnHandleClass : 'resize-handle-active',
		editableSelector : ['table.editable'],
		formClassName : 'editable-cell-form',
		noEditClass : 'noedit',
		editAjaxURI : '/',
		editAjaxOptions : {}
	},
	_tblcount : 0,
	_cellcount : 0,
	load : function() {
		if(TableKit.options.autoLoad) {
			if(TableKit.options.sortable) {
				$A(TableKit.options.sortableSelector).each(function(s){
					$$(s).each(function(t) {
						TableKit.Sortable.init(t);
					});
				});
			}
			if(TableKit.options.resizable) {
				$A(TableKit.options.resizableSelector).each(function(s){
					$$(s).each(function(t) {
						TableKit.Resizable.init(t);
					});
				});
			}
			if(TableKit.options.editable) {
				$A(TableKit.options.editableSelector).each(function(s){
					$$(s).each(function(t) {
						TableKit.Editable.init(t);
					});
				});
			}
		}
	}
});

TableKit.Rows = {
	stripe : function(table) {
		var rows = TableKit.getBodyRows(table);
		rows.each(function(r,i) {
			TableKit.Rows.addStripeClass(table,r,i);
		});
	},
	addStripeClass : function(t,r,i) {
		t = t || r.up('table');
		var op = TableKit.option('rowEvenClass rowOddClass', t.id);
		var css = ((i+1)%2 === 0 ? op[0] : op[1]);
		// using prototype's assClassName/RemoveClassName was not efficient for large tables, hence:
		var cn = r.className.split(/\s+/);
		var newCn = [];
		for(var x = 0, l = cn.length; x < l; x += 1) {
			if(cn[x] !== op[0] && cn[x] !== op[1]) { newCn.push(cn[x]); }
		}
		newCn.push(css);
		r.className = newCn.join(" ");
	}
};

TableKit.Sortable = {
	init : function(elm, options){
		var table = $(elm);
		if(table.tagName !== "TABLE") {
			return;
		}
		TableKit.register(table,Object.extend(options || {},{sortable:true}));
		var sortFirst;
		var cells = TableKit.getHeaderCells(table);
		var op = TableKit.option('noSortClass columnClass sortFirstAscendingClass sortFirstDecendingClass', table.id);
		cells.each(function(c){
			c = $(c);
			if(!c.hasClassName(op.noSortClass)) {
				Event.observe(c, 'mousedown', TableKit.Sortable._sort);
				c.addClassName(op.columnClass);
				if(c.hasClassName(op.sortFirstAscendingClass) || c.hasClassName(op.sortFirstDecendingClass)) {
					sortFirst = c;
				}
			}
		});

		if(sortFirst) {
			if(sortFirst.hasClassName(op.sortFirstAscendingClass)) {
				TableKit.Sortable.sort(table, sortFirst, 1);
			} else {
				TableKit.Sortable.sort(table, sortFirst, -1);
			}
		} else { // just add row stripe classes
			TableKit.Rows.stripe(table);
		}
	},
	reload : function(table) {
		table = $(table);
		var cells = TableKit.getHeaderCells(table);
		var op = TableKit.option('noSortClass columnClass', table.id);
		cells.each(function(c){
			c = $(c);
			if(!c.hasClassName(op.noSortClass)) {
				Event.stopObserving(c, 'mousedown', TableKit.Sortable._sort);
				c.removeClassName(op.columnClass);
			}
		});
		TableKit.Sortable.init(table);
	},
	_sort : function(e) {
		if(TableKit.Resizable._onHandle) {return;}
		e = TableKit.e(e);
		Event.stop(e);
		var cell = Event.element(e);
		while(!(cell.tagName && cell.tagName.match(td))) {
			cell = cell.parentNode;
		}
		TableKit.Sortable.sort(null, cell);
	},
	sort : function(table, index, order) {
		var cell;
		if(typeof index === 'number') {
			if(!table || (table.tagName && table.tagName !== "TABLE")) {
				return;
			}
			table = $(table);
			index = Math.min(table.rows[0].cells.length, index);
			index = Math.max(1, index);
			index -= 1;
			cell = (table.tHead && table.tHead.rows.length > 0) ? $(table.tHead.rows[table.tHead.rows.length-1].cells[index]) : $(table.rows[0].cells[index]);
		} else {
			cell = $(index);
			table = table ? $(table) : cell.up('table');
			index = TableKit.getCellIndex(cell);
		}
		var op = TableKit.option('noSortClass descendingClass ascendingClass', table.id);
		
		if(cell.hasClassName(op.noSortClass)) {return;}	
		
		order = order ? order : (cell.hasClassName(op.descendingClass) ? 1 : -1);
		var rows = TableKit.getBodyRows(table);

		if(cell.hasClassName(op.ascendingClass) || cell.hasClassName(op.descendingClass)) {
			rows.reverse(); // if it was already sorted we just need to reverse it.
		} else {
			var datatype = TableKit.Sortable.getDataType(cell,index,table);
			var tkst = TableKit.Sortable.types;
			rows.sort(function(a,b) {
				return order * tkst[datatype].compare(TableKit.getCellText(a.cells[index]),TableKit.getCellText(b.cells[index]));
			});
		}
		var tb = table.tBodies[0];
		var tkr = TableKit.Rows;
		rows.each(function(r,i) {
			tb.appendChild(r);
			tkr.addStripeClass(table,r,i);
		});
		var hcells = TableKit.getHeaderCells(null, cell);
		$A(hcells).each(function(c,i){
			c = $(c);
			c.removeClassName(op.ascendingClass);
			c.removeClassName(op.descendingClass);
			if(index === i) {
				if(order === 1) {
					c.removeClassName(op.descendingClass);
					c.addClassName(op.ascendingClass);
				} else {
					c.removeClassName(op.ascendingClass);
					c.addClassName(op.descendingClass);
				}
			}
		});
	},
	types : {},
	detectors : [],
	addSortType : function() {
		$A(arguments).each(function(o){
			TableKit.Sortable.types[o.name] = o;
		});
	},
	getDataType : function(cell,index,table) {
		cell = $(cell);
		index = (index || index === 0) ? index : TableKit.getCellIndex(cell);
		
		var colcache = TableKit.Sortable._coltypecache;
		var cache = colcache[table.id] ? colcache[table.id] : (colcache[table.id] = {});
		
		if(!cache[index]) {
			var t = '';
			// first look for a data type id on the heading row cell
			if(cell.id && TableKit.Sortable.types[cell.id]) {
				t = cell.id;
			}
			t = cell.classNames().detect(function(n){ // then look for a data type classname on the heading row cell
				return (TableKit.Sortable.types[n]) ? true : false;
			});
			if(!t) {
				var rows = TableKit.getBodyRows(table);
				cell = rows[0].cells[index]; // grab same index cell from body row to try and match data type
				t = TableKit.Sortable.detectors.detect(
						function(d){
							return TableKit.Sortable.types[d].detect(TableKit.getCellText(cell));
						});
			}
			cache[index] = t;
		}
		return cache[index];
	},
	_coltypecache : {}
};

TableKit.Sortable.detectors = $A($w('date-iso date date-eu date-au time currency datasize number casesensitivetext text')); // setting it here because Safari complained when I did it above...

TableKit.Sortable.Type = Class.create();
TableKit.Sortable.Type.prototype = {
	initialize : function(name, options){
		this.name = name;
		options = Object.extend({
			normal : function(v){
				return v;
			},
			pattern : /.*/
		}, options || {});
		this.normal = options.normal;
		this.pattern = options.pattern;
		if(options.compare) {
			this.compare = options.compare;
		}
		if(options.detect) {
			this.detect = options.detect;
		}
	},
	compare : function(a,b){
		return TableKit.Sortable.Type.compare(this.normal(a), this.normal(b));
	},
	detect : function(v){
		return this.pattern.test(v);
	}
};

TableKit.Sortable.Type.compare = function(a,b) {
	return a < b ? -1 : a === b ? 0 : 1;
};

TableKit.Sortable.addSortType(
	new TableKit.Sortable.Type('number', {
		pattern : /^[-+]?[\d]*\.?[\d]+(?:[eE][-+]?[\d]+)?/,
		normal : function(v) {
			// This will grab the first thing that looks like a number from a string, so you can use it to order a column of various srings containing numbers.
			v = parseFloat(v.replace(/^.*?([-+]?[\d]*\.?[\d]+(?:[eE][-+]?[\d]+)?).*$/,"$1"));
			return isNaN(v) ? 0 : v;
		}}),
	new TableKit.Sortable.Type('text',{
		normal : function(v) {
			return v ? v.toLowerCase() : '';
		}}),
	new TableKit.Sortable.Type('casesensitivetext',{pattern : /^[A-Z]+$/}),
	new TableKit.Sortable.Type('datasize',{
		pattern : /^[-+]?[\d]*\.?[\d]+(?:[eE][-+]?[\d]+)?\s?[k|m|g|t]b$/i,
		normal : function(v) {
			var r = v.match(/^([-+]?[\d]*\.?[\d]+([eE][-+]?[\d]+)?)\s?([k|m|g|t]?b)?/i);
			var b = r[1] ? Number(r[1]).valueOf() : 0;
			var m = r[3] ? r[3].substr(0,1).toLowerCase() : '';
			var result = b;
			switch(m) {
				case  'k':
					result = b * 1024;
					break;
				case  'm':				
					result = b * 1024 * 1024;
					break;
				case  'g':
					result = b * 1024 * 1024 * 1024;
					break;
				case  't':
					result = b * 1024 * 1024 * 1024 * 1024;
					break;
			}
			return result;
		}}),
	new TableKit.Sortable.Type('date-au',{
		pattern : /^\d{2}\/\d{2}\/\d{4}\s?(?:\d{1,2}\:\d{2}(?:\:\d{2})?\s?[a|p]?m?)?/i,
		normal : function(v) {
			if(!this.pattern.test(v)) {return 0;}
			var r = v.match(/^(\d{2})\/(\d{2})\/(\d{4})\s?(?:(\d{1,2})\:(\d{2})(?:\:(\d{2}))?\s?([a|p]?m?))?/i);
			var yr_num = r[3];
			var mo_num = parseInt(r[2],10)-1;
			var day_num = r[1];
			var hr_num = r[4] ? r[4] : 0;
			if(r[7] && r[7].toLowerCase().indexOf('p') !== -1) {
				hr_num = parseInt(r[4],10) + 12;
			}
			var min_num = r[5] ? r[5] : 0;
			var sec_num = r[6] ? r[6] : 0;
			return new Date(yr_num, mo_num, day_num, hr_num, min_num, sec_num, 0).valueOf();
		}}),
	new TableKit.Sortable.Type('date-us',{
		pattern : /^\d{2}\/\d{2}\/\d{4}\s?(?:\d{1,2}\:\d{2}(?:\:\d{2})?\s?[a|p]?m?)?/i,
		normal : function(v) {
			if(!this.pattern.test(v)) {return 0;}
			var r = v.match(/^(\d{2})\/(\d{2})\/(\d{4})\s?(?:(\d{1,2})\:(\d{2})(?:\:(\d{2}))?\s?([a|p]?m?))?/i);
			var yr_num = r[3];
			var mo_num = parseInt(r[1],10)-1;
			var day_num = r[2];
			var hr_num = r[4] ? r[4] : 0;
			if(r[7] && r[7].toLowerCase().indexOf('p') !== -1) {
				hr_num = parseInt(r[4],10) + 12;
			}
			var min_num = r[5] ? r[5] : 0;
			var sec_num = r[6] ? r[6] : 0;
			return new Date(yr_num, mo_num, day_num, hr_num, min_num, sec_num, 0).valueOf();
		}}),
	new TableKit.Sortable.Type('date-eu',{
		pattern : /^\d{2}-\d{2}-\d{4}/i,
		normal : function(v) {
			if(!this.pattern.test(v)) {return 0;}
			var r = v.match(/^(\d{2})-(\d{2})-(\d{4})/);
			var yr_num = r[3];
			var mo_num = parseInt(r[2],10)-1;
			var day_num = r[1];
			return new Date(yr_num, mo_num, day_num).valueOf();
		}}),
	new TableKit.Sortable.Type('date-iso',{
		pattern : /[\d]{4}-[\d]{2}-[\d]{2}(?:T[\d]{2}\:[\d]{2}(?:\:[\d]{2}(?:\.[\d]+)?)?(Z|([-+][\d]{2}:[\d]{2})?)?)?/, // 2005-03-26T19:51:34Z
		normal : function(v) {
			if(!this.pattern.test(v)) {return 0;}
		    var d = v.match(/([\d]{4})(-([\d]{2})(-([\d]{2})(T([\d]{2}):([\d]{2})(:([\d]{2})(\.([\d]+))?)?(Z|(([-+])([\d]{2}):([\d]{2})))?)?)?)?/);		
		    var offset = 0;
		    var date = new Date(d[1], 0, 1);
		    if (d[3]) { date.setMonth(d[3] - 1) ;}
		    if (d[5]) { date.setDate(d[5]); }
		    if (d[7]) { date.setHours(d[7]); }
		    if (d[8]) { date.setMinutes(d[8]); }
		    if (d[10]) { date.setSeconds(d[10]); }
		    if (d[12]) { date.setMilliseconds(Number("0." + d[12]) * 1000); }
		    if (d[14]) {
		        offset = (Number(d[16]) * 60) + Number(d[17]);
		        offset *= ((d[15] === '-') ? 1 : -1);
		    }
		    offset -= date.getTimezoneOffset();
		    if(offset !== 0) {
		    	var time = (Number(date) + (offset * 60 * 1000));
		    	date.setTime(Number(time));
		    }
			return date.valueOf();
		}}),
	new TableKit.Sortable.Type('date',{
		pattern: /^(?:sun|mon|tue|wed|thu|fri|sat)\,\s\d{1,2}\s(?:jan|feb|mar|apr|may|jun|jul|aug|sep|oct|nov|dec)\s\d{4}(?:\s\d{2}\:\d{2}(?:\:\d{2})?(?:\sGMT(?:[+-]\d{4})?)?)?/i, //Mon, 18 Dec 1995 17:28:35 GMT
		compare : function(a,b) { // must be standard javascript date format
			if(a && b) {
				return TableKit.Sortable.Type.compare(new Date(a),new Date(b));
			} else {
				return TableKit.Sortable.Type.compare(a ? 1 : 0, b ? 1 : 0);
			}
		}}),
	new TableKit.Sortable.Type('time',{
		pattern : /^\d{1,2}\:\d{2}(?:\:\d{2})?(?:\s[a|p]m)?$/i,
		compare : function(a,b) {
			var d = new Date();
			var ds = d.getMonth() + "/" + d.getDate() + "/" + d.getFullYear() + " ";
			return TableKit.Sortable.Type.compare(new Date(ds + a),new Date(ds + b));
		}}),
	new TableKit.Sortable.Type('currency',{
		pattern : /^[$£¥€¤]/, // dollar,pound,yen,euro,generic currency symbol
		normal : function(v) {
			return v ? parseFloat(v.replace(/[^-\d\.]/g,'')) : 0;
		}})
);
//set the varriable for getting the top edge of table
var getOffsetTopTable;

TableKit.Resizable = {
	init : function(elm, options){
		var table = $(elm);
		getOffsetTopTable=Position.cumulativeOffset(table);
		if(table.tagName !== "TABLE") {return;}
		TableKit.register(table,Object.extend(options || {},{resizable:true}));		 
		var cells = TableKit.getHeaderCells(table);
		
		cells.each(function(c){
			c = $(c);
			Event.observe(c, 'mouseover', TableKit.Resizable.initDetect);
			Event.observe(c, 'mouseout', TableKit.Resizable.killDetect);
		});
	},
	resize : function(table, index, w) {
		var cell;
		if(typeof index === 'number') {
			if(!table || (table.tagName && table.tagName !== "TABLE")) {return;}
			table = $(table);
			index = Math.min(table.rows[0].cells.length, index);
			index = Math.max(1, index);
			index -= 1;
			cell = (table.tHead && table.tHead.rows.length > 0) ? $(table.tHead.rows[table.tHead.rows.length-1].cells[index]) : $(table.rows[0].cells[index]);
		} else {
			cell = $(index);
			table = table ? $(table) : cell.up('table');
			index = TableKit.getCellIndex(cell);
		}
	
		var pad = parseInt(cell.getStyle('paddingLeft'),10) + parseInt(cell.getStyle('paddingRight'),10);
		w=(w*100)/GetWidth();//convert the relative width into percent
                //alert(w)
		cell.setStyle({'width' : w + '%'});
	},
	initDetect : function(e) {
		e = TableKit.e(e);
		
		var cell = Event.element(e);
		if(getTableLengthtStatus()==true){return;}
		if(cell.tagName=='INPUT'||cell.tagName=='IMG'){return;}
		Event.observe(cell, 'mousemove', TableKit.Resizable.detectHandle);
		Event.observe(cell, 'mousedown', TableKit.Resizable.startResize);
	},
	detectHandle : function(e) {
		e = TableKit.e(e);
		var cell = Event.element(e);
	        
	        if(TableKit.Resizable.pointerPos(cell,Event.pointerX(e),Event.pointerY(e))){
  			cell.addClassName(TableKit.option('resizeOnHandleClass', cell.up('table').id)[0]);
  			TableKit.Resizable._onHandle = true;
  		} else {
  			cell.removeClassName(TableKit.option('resizeOnHandleClass', cell.up('table').id)[0]);
  			TableKit.Resizable._onHandle = false;
  		}
	},
	killDetect : function(e) {
		e = TableKit.e(e);
		TableKit.Resizable._onHandle = false;
		var cell = Event.element(e);
	
		Event.stopObserving(cell, 'mousemove', TableKit.Resizable.detectHandle);
		Event.stopObserving(cell, 'mousedown', TableKit.Resizable.startResize);
		cell.removeClassName(TableKit.option('resizeOnHandleClass', cell.up('table').id)[0]);
	},
	startResize : function(e) {
		e = TableKit.e(e);
		if(!TableKit.Resizable._onHandle) {return;}
		var cell = Event.element(e);
		Event.stopObserving(cell, 'mousemove', TableKit.Resizable.detectHandle);
		Event.stopObserving(cell, 'mousedown', TableKit.Resizable.startResize);
		Event.stopObserving(cell, 'mouseout', TableKit.Resizable.killDetect);
		
		TableKit.Resizable._cell = cell;
		var table = cell.up('table');
		TableKit.Resizable._tbl = table;
		var heightTable=getHeightTable();
		if(table.getDimensions().height<heightTable )
		 heightTable=table.getDimensions().height;
		if(TableKit.option('showHandle', table.id)[0]) {
			TableKit.Resizable._handle = $(document.createElement('div')).addClassName('resize-handle').setStyle({
				'top' :getOffsetTopTable[1]+ 'px',
				'left' : Event.pointerX(e) + 'px',
				'height' : heightTable + 'px'
				
			});
			document.body.appendChild(TableKit.Resizable._handle);
		}
		Event.observe(document, 'mousemove', TableKit.Resizable.drag);
		Event.observe(document, 'mouseup', TableKit.Resizable.endResize);
		Event.stop(e);
	},
	endResize : function(e) {
		e = TableKit.e(e);
		var cell = TableKit.Resizable._cell;
		TableKit.Resizable.resize(null, cell, (Event.pointerX(e) - Position.cumulativeOffset(cell)[0]));
		Event.stopObserving(document, 'mousemove', TableKit.Resizable.drag);
		Event.stopObserving(document, 'mouseup', TableKit.Resizable.endResize);
		if(TableKit.option('showHandle', TableKit.Resizable._tbl.id)[0]) {
			$$('div.resize-handle').each(function(elm){
				document.body.removeChild(elm);
			});
		}
		Event.observe(cell, 'mouseout', TableKit.Resizable.killDetect);
		TableKit.Resizable._tbl = TableKit.Resizable._handle = TableKit.Resizable._cell = null;
		Event.stop(e);
	},
	drag : function(e) {
		e = TableKit.e(e);
		if(TableKit.Resizable._handle === null) {
			try {
				TableKit.Resizable.resize(TableKit.Resizable._tbl, TableKit.Resizable._cell, (Event.pointerX(e) - Position.cumulativeOffset(TableKit.Resizable._cell)[0]));
			} catch(e) {}
		} else {
			TableKit.Resizable._handle.setStyle({'left' : Event.pointerX(e) + 'px'});
		}
		return false;
	},
	pointerPos : function(element, x, y) {
    	var offset = Position.cumulativeOffset(element);
	    return ( x >= offset[0] + element.offsetWidth - 5 &&
	             x <  offset[0] + element.offsetWidth);
  	},
	_onHandle : false,
	_cell : null,
	_tbl : null,
	_handle : null
};



if(window.FastInit) {
	FastInit.addOnLoad(TableKit.load);
} else {
	Event.observe(window, 'load', TableKit.load);
}