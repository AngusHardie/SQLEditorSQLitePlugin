


function SQLEditorProcessTemplate(templateSource)
{
    
    
    var template = Handlebars.compile(templateSource);
    

    
    var functionList = "";
    
    for(var p in container)
    {
        
        
        functionList += p
        
        
    }
    
    return functionList
    
    return template(dataDictionary);
    
}