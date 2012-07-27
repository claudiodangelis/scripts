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

	var tmpSnippetJsonObj	= {};
	var snippetJsonObj 		= {};

	tmpSnippetJsonObj.cat 	= [];
	snippetJsonObj.cat 		= [];
	
	for(i=0;i<jsonData.snippets.length;i++){
		snip=jsonData.snippets[i];
		tmpSnippetJsonObj.cat.push({'id':snip.cat});
	}

	for(i=0;i<tmpSnippetJsonObj.cat.length;i++){
		
		if($.inArray(snip.cat,snippetJsonObj.cat.id) == -1){
			console.log(tmpSnippetJsonObj.cat[i].id +' non presente');
			snippetJsonObj.cat.push({'id':snip.cat});
		}else{
			console.log(snippetJsonObj.cat[i]+' presente');
		}

	}
	//tmpSnippetJsonObj.cat.push({'snippet':'sn'});



	var archetipo = 
	{'cat':[
			{'id':'Python',
			'snippet':[
				{
					'nome':'primo snippet',
					'codice':'codice primo sni'
				},
				
				{
					'nome':'secondo',
					'codice':'codice secondo'
				}
			]},
			
			{'id':'JS'},
			
			{'id':'php'},]
		};

}

function stampaSnippet(nomeFileSnippet,snippet,textEditor){

	var divSnippet		= document.createElement('div');
	var preSnippet		= document.createElement('pre');
	var pTitoloSnippet	= document.createElement('p');
	var titoloSnippet 	= document.createTextNode(nomeFileSnippet+' | '+textEditor);
	var corpoSnippet	= document.createTextNode(snippet);

	divSnippet.appendChild(pTitoloSnippet);
	divSnippet.appendChild(preSnippet);
	pTitoloSnippet.appendChild(titoloSnippet);
	preSnippet.appendChild(corpoSnippet);
	
	document.body.appendChild(divSnippet);
}

