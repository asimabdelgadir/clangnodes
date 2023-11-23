import 'package:bloc/bloc.dart';
import 'package:repository/auth_repository.dart';

class AuthBloc extends Bloc<AuthEven, AuthState> {
  AuthBloc(super.initialState);

  final AuthRepository authRepository = AuthRepository();
}

class AuthState {}

class AuthEven {}
