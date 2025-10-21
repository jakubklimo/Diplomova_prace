// tools & utils
#import "../theme.typ": faculty_logotype, tul_logomark, faculty_color
#import "../lang.typ": lang_id, get_lang_item
#import "../utils.typ": assert_in_dict, assert_in_arr, map_none, assert_dict_has

// thesis types
#import "bp.typ": bp
#import "dp.typ": dp
#import "other.typ": other

#let template_classic(
  // general settings
  language, faculty_id, document_type, citation_file, assignment_document,

  // document info
  title, author, author_pronouns, supervisor, consultant, study_programme, study_specialization,
  year_of_study, abstract, acknowledgement, keywords,

  // content
  content,
) = {
  // argument pre-checking
  let document_types = (
    "bp": bp,
    "dp": dp,
    "other": other,
  )
  assert_in_dict(document_type, document_types, "document type");
  map_none(title, (v) => assert_dict_has((language,), v, "title"));
  map_none(study_programme, (v) => assert_dict_has((language,), v, "study programme"));
  map_none(study_specialization, (v) => assert_dict_has((language,), v, "study specialization"));
  map_none(acknowledgement, (v) => assert_dict_has((language,), v, "acknowledgement content"));

  document_types.at(document_type)(
    faculty_id,
    faculty_color(faculty_id),
    language,
    map_none(assignment_document, (v) => "../../" + v),
    map_none(citation_file, (v) => "../../" + v),
    title,
    author,
    author_pronouns,
    supervisor,
    consultant,
    study_programme,
    study_specialization,
    year_of_study,
    abstract,
    acknowledgement,
    keywords,
    content,
  );
}
