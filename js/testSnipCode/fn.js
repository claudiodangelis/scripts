function leggiSnippets(jsonFile){
	$.getJSON(jsonFile, function(jsonData){
		convertiPerSublimeText2(jsonData);
		convertiPerGeany(jsonData);
	});
}

function convertiPerSublimeText2(jsonData){

	for(i=0;i<jsonData.snippets.length;i++){
		snip=jsonData.snippets[i];

		if(snip.tab == ""){
			tabTrigger = '';
		}else{
			tabTrigger = '\n<tabTrigger>'+snip.tab+'</tabTrigger>';
		}
	
		if(snip.cat == ""){
			scope	= '';
			pathTo	= 'User';
		}else{
			scope='\n<scope>source.'+snip.cat+'</scope>';
			pathTo	= snip.cat;
		}
		
		var snippet = '<snippet>\n<content>\n<![CDATA[\n' +
	    	jsonData.snippets[i].data +'\n]]>\n</content>' +
	    	tabTrigger + scope +
	    	'\n<description>'+snip.name+'</description>\n\</snippet>';
		
		var fileName = '~/.config/sublime-text-2/Packages/'+pathTo+'/'+snip.name.replace(/ /g,'-')+'.sublime-snippet';
		stampaSnippet(fileName,snippet,'Sublime Text 2');
	}
}

function convertiPerGeany(jsonData){

	var snippetJsonObj	= {};
	var snippetJsonObj 	= {};

	snippetJsonObj.cat 	= [];
	snippetJsonObj.cat 	= [];
	
	var visto = [];	// metodo piuttosto rozzo ma assolutamente funzionale

	for(i=0;i<jsonData.snippets.length;i++){

		snip=jsonData.snippets[i];

		if($.inArray(snip.cat,visto)==-1){
			snippetJsonObj.cat.push({'id':snip.cat});
		}

		visto.push(snip.cat);
	}

	for(i=0;i<snippetJsonObj.cat.length;i++){
		snippetJsonObj.cat[i].snippet=[];

	for(j=0;j<jsonData.snippets.length;j++){
		if(snippetJsonObj.cat[i].id==jsonData.snippets[j].cat){

			var singoloSnippetObj = {};
			
			singoloSnippetObj.name=jsonData.snippets[j].name;
			singoloSnippetObj.data=jsonData.snippets[j].data;
			singoloSnippetObj.tab=jsonData.snippets[j].tab;

			snippetJsonObj.cat[i].snippet.push(singoloSnippetObj);
		}
	}

	}

	stampaSnippet('~/.config/geany/snippets.conf',snippetJsonObj,'geany');
}

function stampaSnippet(nomeFileSnippet,snippet,textEditor){

	if(textEditor=='geany'){

	 	tmpSnippet='';
	 	for(i=0;i<snippet.cat.length;i++){
	 		if(snippet.cat[i].id==''){
	 			tmpSnippet+='[Default]\n';
	 		}else{
	 			tmpSnippet+='['+snippet.cat[i].id+']\n';
	 		}

	 		for(j=0;j<snippet.cat[i].snippet.length;j++){
	 			if(snippet.cat[i].snippet[j].tab!=''){	// il formato delle snippets di geany richiede un tab trigger
	 				tmpSnippet+=snippet.cat[i].snippet[j].tab+'='+snippet.cat[i].snippet[j].data.replace(/\n/g,'\\n')+'\n';
	 			}
	 		}

	 		tmpSnippet+='\n';
	 	}

		snippet = tmpSnippet;
	}


	var divSnippet		= document.createElement('div');
	var preSnippet		= document.createElement('pre');
	var pTitoloSnippet	= document.createElement('p');
	var titoloSnippet 	= document.createTextNode(textEditor +' # '+nomeFileSnippet);
	var corpoSnippet	= document.createTextNode(snippet);

	divSnippet.appendChild(pTitoloSnippet);
	divSnippet.appendChild(preSnippet);
	pTitoloSnippet.appendChild(titoloSnippet);
	preSnippet.appendChild(corpoSnippet);
	
	document.body.appendChild(divSnippet);
}